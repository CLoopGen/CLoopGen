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
    int temp[16];
    int idx = 0;
    for (pixel_y = 0; pixel_y < 4; pixel_y++) {
        for (pixel_x = 0; pixel_x < 4; pixel_x++) {
            temp[idx] = pixels[prev_block_ptr++];
            idx++;
        }
        prev_block_ptr += row_inc;
    }
    idx = 0;
    for (pixel_y = 0; pixel_y < 4; pixel_y++) {
        for (pixel_x = 0; pixel_x < 4; pixel_x++) {
            pixels[block_ptr++] = temp[idx++];
        }
        block_ptr += row_inc;
    }
}
