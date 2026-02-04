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
    for (pixel_y = 0; pixel_y < 4; ++pixel_y) {
        for (pixel_x = 0; pixel_x < 4; ++pixel_x) {
            if (!(pixel_x == 2 && pixel_y == 2)) {
                pixels[block_ptr++] = pixels[prev_block_ptr++];
            } else {
                block_ptr++;
                prev_block_ptr++;
            }
        }
        block_ptr += row_inc;
        prev_block_ptr += row_inc;
    }
}
