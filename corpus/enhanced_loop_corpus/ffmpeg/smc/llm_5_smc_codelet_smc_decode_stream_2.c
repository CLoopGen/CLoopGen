#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned char * pixels;
extern int pixel_x;
extern int pixel_y;
extern int row_inc;
extern int block_ptr;
extern int pixel;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (pixel_y = 0; pixel_y < 4; pixel_y++) {
        for (pixel_x = 0; pixel_x < 4; pixel_x++) {
            pixels[block_ptr++] = pixel;
            if (pixel_x == 1 && pixel_y == 1) {
                block_ptr += 2; 
            }
        }
        block_ptr += row_inc;
    }
}
