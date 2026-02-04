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
    // Variant 1: Consecutive Memory Access with Prefetched Row Pointer
    // Instead of computing 'out[x + y * stride]' repeatedly, precompute the row base address.
    // Also, access grps in a more cache-friendly sequential manner by reordering computations.

    uint8_t *row;
    uint32_t temp_col;
    uint8_t local_cols[4];

    for (y = 0; y < height; y++) {
        row = out + y * stride;
        temp_col = col;

        // Prefetch group values used for this row to reduce redundant shifts and indexing
        if (grps) {
            local_cols[0] = grps[3 * (y >> 1)];
            cols[0] = local_cols[0];
        }

        for (x = 0; x < width; x++) {
            if (grps)
                local_cols[1] = grps[(x >> 1) + 1];
            row[x] = cols[temp_col & ((1 << bpp) - 1)];
            temp_col >>= bpp;
        }
    }
}
