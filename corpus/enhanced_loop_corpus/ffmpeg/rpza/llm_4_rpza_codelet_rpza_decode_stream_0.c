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
    for (pixel_y = 0; pixel_y < 4; ++pixel_y) {
        for (pixel_x = 0; pixel_x < 4; ++pixel_x) {
            if ((pixel_y & 1) == 0 || pixel_x < 2) {
                pixels[block_ptr] = colorA;
            }
            block_ptr++;
        }
        block_ptr += row_inc;
    }
}
