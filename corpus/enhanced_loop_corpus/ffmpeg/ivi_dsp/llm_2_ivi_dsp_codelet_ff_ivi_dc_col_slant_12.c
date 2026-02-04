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
    // Variant 1: Consecutive memory access using a flat index instead of 2D-style pitch-based access
    int16_t *out_ptr = out;
    for (y = 0; y < blk_size; y++) {
        *out_ptr = dc_coeff;
        out_ptr++;
        for (x = 1; x < blk_size; x++, out_ptr++)
            *out_ptr = 0;
        out_ptr += pitch - blk_size; // Adjust pointer to next row accounting for pitch
    }
}
