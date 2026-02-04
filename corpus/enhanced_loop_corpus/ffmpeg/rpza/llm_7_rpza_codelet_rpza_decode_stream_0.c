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
    int temp_offset = 0;
    for (pixel_y = 0; pixel_y < 4; pixel_y++) {
        int row_base = temp_offset + pixel_y * (4 + row_inc);
        for (pixel_x = 0; pixel_x < 4; pixel_x++) {
            int index = row_base + pixel_x;
            pixels[block_ptr + index] = colorA;
        }
    }
    block_ptr += 4 * 4 + 3 * row_inc;
}
