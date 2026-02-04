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
        int local_row_inc = row_inc;
        int local_block_ptr = block_ptr;
        int local_prev_block_ptr = prev_block_ptr;
        for (pixel_x = 0; pixel_x < 4; pixel_x++) {
            pixels[local_block_ptr + pixel_x] = pixels[local_prev_block_ptr + pixel_x];
        }
        block_ptr += 4 + local_row_inc;
        prev_block_ptr += 4 + local_row_inc;
    }
}
