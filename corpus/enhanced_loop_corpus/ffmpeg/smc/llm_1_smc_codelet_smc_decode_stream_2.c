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
        pixels[block_ptr++] = pixel;
        pixels[block_ptr++] = pixel;
        pixels[block_ptr++] = pixel;
        pixels[block_ptr++] = pixel;
        block_ptr += row_inc;
    }
}
