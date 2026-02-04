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
    // Variant 2: Strided memory access using index scaling
    int stride = row_inc + 4; // effective row length in units of elements
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            int idx = i * stride + j;
            pixels[block_ptr + idx] = pixels[prev_block_ptr + idx];
        }
    }
    block_ptr += 4 * stride;
    prev_block_ptr += 4 * stride;
}
