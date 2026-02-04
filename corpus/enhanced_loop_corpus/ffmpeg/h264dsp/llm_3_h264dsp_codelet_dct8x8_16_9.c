#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *coef;
extern int i;
extern int16_t tmp[64];

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    for (i = 0; i < 8; i++) {
        // Use strided access via index array to simulate non-consecutive memory pattern
        const int indices[8] = {0, 1, 2, 3, 4, 5, 6, 7}; // Explicit indexing for clarity and future modification
        int16_t *src_row = tmp + 8 * i;
        int16_t *dst_col = coef + i;

        const int a0 = src_row[indices[0]] + src_row[indices[7]];
        const int a1 = src_row[indices[0]] - src_row[indices[7]];
        const int a2 = src_row[indices[1]] + src_row[indices[6]];
        const int a3 = src_row[indices[1]] - src_row[indices[6]];
        const int a4 = src_row[indices[2]] + src_row[indices[5]];
        const int a5 = src_row[indices[2]] - src_row[indices[5]];
        const int a6 = src_row[indices[3]] + src_row[indices[4]];
        const int a7 = src_row[indices[3]] - src_row[indices[4]];

        const int b0 = a0 + a6;
        const int b1 = a2 + a4;
        const int b2 = a0 - a6;
        const int b3 = a2 - a4;
        const int b4 = a3 + a5 + (a1 + (a1 >> 1));
        const int b5 = a1 - a7 - (a5 + (a5 >> 1));
        const int b6 = a1 + a7 - (a3 + (a3 >> 1));
        const int b7 = a3 - a5 + (a7 + (a7 >> 1));

        // Strided write using precomputed offsets
        const int out_indices[8] = {0, 8, 16, 24, 32, 40, 48, 56}; // 8*i stride in output
        dst_col[out_indices[0]] = b0 + b1;
        dst_col[out_indices[1]] = b4 + (b7 >> 2);
        dst_col[out_indices[2]] = b2 + (b3 >> 1);
        dst_col[out_indices[3]] = b5 + (b6 >> 2);
        dst_col[out_indices[4]] = b0 - b1;
        dst_col[out_indices[5]] = b6 - (b5 >> 2);
        dst_col[out_indices[6]] = (b2 >> 1) - b3;
        dst_col[out_indices[7]] = (b4 >> 2) - b7;
    }
}
