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
    // Variant 1: Consecutive memory access with pointer arithmetic
    unsigned char *dst = &pixels[block_ptr];
    unsigned char *src = &pixels[prev_block_ptr];
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            *dst++ = *src++;
        }
        dst += row_inc;
        src += row_inc;
    }
    block_ptr = dst - pixels;
    prev_block_ptr = src - pixels;
}
