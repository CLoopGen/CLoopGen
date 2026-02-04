#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int height;
extern int width;
extern int x;
extern int y;
extern  int8_t *filter;
extern uint16_t *src;
extern ptrdiff_t srcstride;
extern int16_t *tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with transposed indexing
    // Simulates a column-major traversal by swapping loop order conceptually via strided access
    // This changes cache behavior and access pattern to stress different memory bandwidth characteristics

    int16_t *tmp_base = tmp;
    uint16_t *src_base = src;

    for (x = 0; x < width; x++) {
        for (y = 0; y < height + 7; y++) {
            uint16_t *src_pos = src_base + y * srcstride + x;
            int16_t *tmp_pos = tmp_base + y * 64 + x;

            *tmp_pos = (
                filter[0] * src_pos[-3] +
                filter[1] * src_pos[-2] +
                filter[2] * src_pos[-1] +
                filter[3] * src_pos[ 0] +
                filter[4] * src_pos[ 1] +
                filter[5] * src_pos[ 2] +
                filter[6] * src_pos[ 3] +
                filter[7] * src_pos[ 4]
            ) >> 2;
        }
    }
}
