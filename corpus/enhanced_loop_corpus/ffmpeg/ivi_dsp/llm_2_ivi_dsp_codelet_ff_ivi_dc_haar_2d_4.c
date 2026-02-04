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
    // Variant 1: Consecutive memory access using pointer arithmetic without indexing
    int16_t *ptr = out;
    for (y = 0; y < blk_size; y++) {
        for (x = 0; x < blk_size; x++) {
            *ptr++ = dc_coeff;
        }
        ptr += pitch - blk_size; // Jump to the start of the next row using pitch
    }
}
