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
    // Variant 2: Strided memory access - process column-wise instead of row-wise
    int stride = row_inc + 4; // Assuming row_inc accounts for end-of-row padding
    for (pixel_x = 0; pixel_x < 4; pixel_x++) {
        for (pixel_y = 0; pixel_y < 4; pixel_y++) {
            int curr_index = block_ptr + pixel_y * stride + pixel_x;
            int prev_index = prev_block_ptr + pixel_y * stride + pixel_x;
            pixels[curr_index] = pixels[prev_index];
        }
    }
    // Update block_ptr and prev_block_ptr to reflect advancement by 4 rows
    block_ptr += 4 * stride;
    prev_block_ptr += 4 * stride;
}
