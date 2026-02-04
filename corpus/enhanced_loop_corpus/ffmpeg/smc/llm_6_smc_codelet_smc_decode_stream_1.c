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
    uint8_t temp[16];
    int idx = 0;
    for (pixel_y = 0; pixel_y < 4; pixel_y++) {
        for (pixel_x = 0; pixel_x < 4; pixel_x++) {
            temp[idx++] = pixels[prev_block_ptr++];
        }
        prev_block_ptr += row_inc;
    }
    for (int i = 0; i < 16; i++) {
        pixels[block_ptr + i] = temp[i];
    }
    block_ptr += 16 + 3 * row_inc;
}
