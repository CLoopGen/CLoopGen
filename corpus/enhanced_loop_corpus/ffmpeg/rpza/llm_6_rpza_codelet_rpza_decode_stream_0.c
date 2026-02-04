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
    int temp_block_ptr = block_ptr;
    for (pixel_y = 0; pixel_y < 4; pixel_y++) {
        uint16_t local_color = colorA;
        for (pixel_x = 0; pixel_x < 4; pixel_x++) {
            pixels[temp_block_ptr] = local_color;
            temp_block_ptr++;
        }
        temp_block_ptr += row_inc;
    }
    block_ptr = temp_block_ptr;
}
