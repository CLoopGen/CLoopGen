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
    // Variant 2: Strided memory access with indirect indexing via pointer arithmetic
    // Use a pointer to traverse the pixels array with variable stride per row
    uint16_t *p = &pixels[block_ptr];
    for (pixel_y = 0; pixel_y < 4; pixel_y++) {
        uint16_t *row_p = p;
        for (pixel_x = 0; pixel_x < 4; pixel_x++) {
            *row_p = colorA;
            row_p++;
        }
        p += 4 + row_inc; // Advance pointer by full row width including increment
    }
}
