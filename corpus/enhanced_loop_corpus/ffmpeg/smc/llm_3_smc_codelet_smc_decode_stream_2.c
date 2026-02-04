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
    // Variant 2: Strided memory access using a single loop with explicit row strides
    // Access memory with a fixed stride corresponding to row width (simulating 4-element rows)
    int base_ptr = block_ptr;
    for (pixel_y = 0; pixel_y < 4; pixel_y++) {
        int row_base = base_ptr + pixel_y * (4 + row_inc);
        for (pixel_x = 0; pixel_x < 4; pixel_x++) {
            pixels[row_base + pixel_x] = pixel;
        }
    }
    block_ptr = base_ptr + 4 * (4 + row_inc); // Update block_ptr as in original: 4 rows, each with row_inc gap
}
