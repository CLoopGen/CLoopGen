#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int row_inc;
extern uint16_t colorA;
extern uint16_t *pixels;
extern int block_ptr;
extern int pixel_x;
extern int pixel_y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with flattened index calculation
    // Instead of updating block_ptr incrementally inside nested loops,
    // compute the target index directly using row-major order to enable consecutive writes.
    int base_index = block_ptr;
    for (pixel_y = 0; pixel_y < 4; pixel_y++) {
        int row_start = base_index + pixel_y * (4 + row_inc);
        for (pixel_x = 0; pixel_x < 4; pixel_x++) {
            pixels[row_start + pixel_x] = colorA;
        }
    }
}
