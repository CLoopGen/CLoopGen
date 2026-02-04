#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *out;
extern ptrdiff_t pitch;
extern int blk_size;
extern int x;
extern int y;
extern int16_t dc_coeff;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access – write every other element first, then fill gaps (unrolled-like pattern)
    for (y = 0; y < blk_size; out += pitch, y++) {
        // First pass: write dc_coeff and zero out even indices
        if (blk_size > 0) out[0] = dc_coeff;
        for (x = 2; x < blk_size; x += 2)
            out[x] = 0;

        // Second pass: fill odd indices with zero
        for (x = 1; x < blk_size; x += 2)
            out[x] = 0;
    }
}
