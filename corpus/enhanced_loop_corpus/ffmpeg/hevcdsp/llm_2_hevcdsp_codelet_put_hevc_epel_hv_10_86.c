#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *dst;
extern int height;
extern int width;
extern int x;
extern int y;
extern  int8_t *filter;
extern int16_t *tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with manual offset accumulation
    // Instead of relying on pointer arithmetic with strides of 64, we use a flat index
    // and access tmp as a 2D array laid out in row-major order, accessing consecutive elements.
    int idx = 0;
    for (y = 0; y < height; y++) {
        for (x = 0; x < width; x++) {
            int base = idx + x;
            dst[x] = (filter[0] * tmp[base - 64] +
                      filter[1] * tmp[base] +
                      filter[2] * tmp[base + 64] +
                      filter[3] * tmp[base + 128]) >> 6;
        }
        idx += 64;
        dst += 64;
    }
}
