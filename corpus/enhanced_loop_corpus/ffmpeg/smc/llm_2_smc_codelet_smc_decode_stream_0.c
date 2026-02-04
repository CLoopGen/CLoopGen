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
    // Variant 1: Consecutive memory access with precomputed base pointers
    unsigned char *curr_base = &pixels[block_ptr];
    unsigned char *prev_base = &pixels[prev_block_ptr];
    int total_inc = row_inc + 4;

    for (pixel_y = 0; pixel_y < 4; pixel_y++) {
        for (pixel_x = 0; pixel_x < 4; pixel_x++) {
            *curr_base++ = *prev_base++;
        }
        curr_base += row_inc;
        prev_base += row_inc;
    }

    block_ptr = curr_base - pixels;
    prev_block_ptr = prev_base - pixels;
}
