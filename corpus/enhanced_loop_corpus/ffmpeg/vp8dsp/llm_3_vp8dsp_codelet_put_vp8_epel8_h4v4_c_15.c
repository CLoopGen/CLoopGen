#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern ptrdiff_t dststride;
extern int h;
extern  uint8_t *filter;
extern  uint8_t *cm;
extern int x;
extern int y;
extern uint8_t *tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access using precomputed indices
    // We change the access pattern to use an explicit stride-based index array
    // to simulate irregular or strided memory access, possibly modeling gather patterns.

    const int offsets[5] = {-8, 0, 8, 16}; // Equivalent to x-8, x, x+8, x+16 (relative to x)
    int idx[8]; // Precompute linear indices for tmp access

    for (y = 0; y < h; y++) {
        for (x = 0; x < 8; x++) {
            idx[x] = x * 8 + y * 64; // Linear index into tmp with stride 8 per row
        }
        for (x = 0; x < 8; x++) {
            int sum = filter[2] * tmp[idx[x] + offsets[1]]
                    - filter[1] * tmp[idx[x] + offsets[0]]
                    + filter[3] * tmp[idx[x] + offsets[2]]
                    - filter[4] * tmp[idx[x] + offsets[3]];
            dst[x] = cm[(sum + 64) >> 7];
        }
        dst += dststride;
        tmp += 8;
    }
}
