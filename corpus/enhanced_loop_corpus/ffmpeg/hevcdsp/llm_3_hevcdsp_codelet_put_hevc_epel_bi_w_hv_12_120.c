#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int height;
extern int width;
extern int x;
extern int y;
extern uint16_t *src;
extern ptrdiff_t srcstride;
extern  int8_t *filter;
extern int16_t *tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Use strided memory access by processing transposed pattern (simulate column-major traversal)
    // We reinterpret the iteration to step through memory with larger strides
    uint16_t *src_base = src;
    int16_t *tmp_base = tmp;

    for (x = 0; x < width; x++) {
        for (y = 0; y < height + 3; y++) {
            uint16_t *src_row = src_base + y * srcstride;
            tmp_base[x + y * 64] = (
                filter[0] * src_row[x - 1] +
                filter[1] * src_row[x] +
                filter[2] * src_row[x + 1] +
                filter[3] * src_row[x + 2]
            ) >> 4;
        }
    }

    // Update original pointers as in the base version (side-effect preservation)
    src = src_base + (height + 3) * srcstride;
    tmp = tmp_base + (height + 3) * 64;
}
