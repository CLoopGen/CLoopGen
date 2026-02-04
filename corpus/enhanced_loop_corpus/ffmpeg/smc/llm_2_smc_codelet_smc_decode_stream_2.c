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
    // Variant 1: Consecutive memory access by precomputing the entire block offset
    // Instead of incrementing block_ptr inside nested loops, calculate target indices consecutively
    int base_ptr = block_ptr;
    for (int i = 0; i < 16; i++) {
        pixels[base_ptr + i] = pixel;
    }
    block_ptr = base_ptr + 16 + 3 * row_inc; // Adjust block_ptr to mimic original final value (4 rows advanced with 3 skips)
}
