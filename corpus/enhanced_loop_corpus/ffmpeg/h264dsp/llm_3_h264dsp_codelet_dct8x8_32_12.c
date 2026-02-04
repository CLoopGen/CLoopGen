#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t *coef;
extern int i;
extern int32_t tmp[64];

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    for (i = 0; i < 8; i++) {
        int32_t *in_row = tmp + 8 * i;
        int32_t *out_col = coef + i;
        // Change memory access to use a fixed offset array for indirect-like indexing
        const int idx[8] = {0, 1, 2, 3, 4, 5, 6, 7};
        const int a0 = in_row[idx[0]] + in_row[idx[7]];
        const int a1 = in_row[idx[0]] - in_row[idx[7]];
        const int a2 = in_row[idx[1]] + in_row[idx[6]];
        const int a3 = in_row[idx[1]] - in_row[idx[6]];
        const int a4 = in_row[idx[2]] + in_row[idx[5]];
        const int a5 = in_row[idx[2]] - in_row[idx[5]];
        const int a6 = in_row[idx[3]] + in_row[idx[4]];
        const int a7 = in_row[idx[3]] - in_row[idx[4]];
        const int b0 = a0 + a6;
        const int b1 = a2 + a4;
        const int b2 = a0 - a6;
        const int b3 = a2 - a4;
        const int b4 = a3 + a5 + (a1 + (a1 >> 1));
        const int b5 = a1 - a7 - (a5 + (a5 >> 1));
        const int b6 = a1 + a7 - (a3 + (a3 >> 1));
        const int b7 = a3 - a5 + (a7 + (a7 >> 1));
        // Strided write: output written with stride 8 (column-major style)
        out_col[8*0] = b0 + b1;
        out_col[8*1] = b4 + (b7 >> 2);
        out_col[8*2] = b2 + (b3 >> 1);
        out_col[8*3] = b5 + (b6 >> 2);
        out_col[8*4] = b0 - b1;
        out_col[8*5] = b6 - (b5 >> 2);
        out_col[8*6] = (b2 >> 1) - b3;
        out_col[8*7] = (b4 >> 2) - b7;
    }
}
