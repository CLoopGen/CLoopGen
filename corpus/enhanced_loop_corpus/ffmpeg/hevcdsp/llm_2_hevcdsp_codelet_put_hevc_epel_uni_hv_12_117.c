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
    // Variant 1: Consecutive memory access with pointer arithmetic unrolling
    uint16_t *src_ptr = src;
    int16_t *tmp_ptr = tmp;
    for (y = 0; y < height + 3; y++) {
        uint16_t *row = src_ptr;
        for (x = 0; x < width; x++) {
            // Access src using base pointer with offset, promoting spatial locality
            int val = (filter[0] * row[x - 1] +
                       filter[1] * row[x] +
                       filter[2] * row[x + 1] +
                       filter[3] * row[x + 2]) >> 4;
            tmp_ptr[x] = (int16_t)val;
        }
        src_ptr += srcstride;
        tmp_ptr += 64;
    }
}
