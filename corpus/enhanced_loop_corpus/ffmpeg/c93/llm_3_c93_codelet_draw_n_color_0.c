#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *out;
extern int stride;
extern int width;
extern int height;
extern int bpp;
extern uint8_t cols[4];
extern uint8_t grps[4];
extern uint32_t col;
extern int x;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect Access via Index Arrays (Simulating Gather Pattern)
    // Use precomputed index arrays to simulate indirect memory access for both `grps` and `out`.
    // This models scenarios where access patterns are non-linear or data-dependent.

    int *x_indices = (int*)malloc(width * sizeof(int));
    int *y_indices = (int*)malloc(height * sizeof(int));
    int *out_offsets = (int*)malloc(width * sizeof(int));

    // Precompute indirect indices for y (used in grps) and output offsets
    for (y = 0; y < height; y++) {
        y_indices[y] = grps ? 3 * (y >> 1) : 0;
    }

    for (x = 0; x < width; x++) {
        x_indices[x] = grps ? (x >> 1) + 1 : 0;
        out_offsets[x] = x;
    }

    uint32_t temp_col;

    for (y = 0; y < height; y++) {
        if (grps)
            cols[0] = grps[y_indices[y]];

        temp_col = col;

        for (x = 0; x < width; x++) {
            if (grps)
                cols[1] = grps[x_indices[x]];

            out[out_offsets[x] + y * stride] = cols[temp_col & ((1 << bpp) - 1)];
            temp_col >>= bpp;
        }
    }

    free(x_indices);
    free(y_indices);
    free(out_offsets);
}
