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
    // Variant 1: Strided memory access with reversed traversal order
    for (y = blk_size - 1; y >= 0; y--) {
        int16_t *row = out + y * pitch;
        for (x = 0; x < blk_size; x += 2) {
            row[x] = dc_coeff;
            if (x + 1 < blk_size)
                row[x + 1] = dc_coeff;
        }
    }
}
