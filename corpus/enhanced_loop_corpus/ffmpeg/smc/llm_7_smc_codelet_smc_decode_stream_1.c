#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned char * pixels;
extern int pixel_x;
extern int pixel_y;
extern int row_inc;
extern int block_ptr;
extern int prev_block_ptr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (pixel_y = 0; pixel_y < 4; pixel_y++) {
        int row_base_curr = block_ptr + pixel_y * (row_inc + 4);
        int row_base_prev = prev_block_ptr + pixel_y * (row_inc + 4);
        for (pixel_x = 0; pixel_x < 4; pixel_x++) {
            pixels[row_base_curr + pixel_x] = pixels[row_base_prev + pixel_x];
        }
    }
    block_ptr += 16 + 3 * row_inc;
    prev_block_ptr += 16 + 3 * row_inc;
}
