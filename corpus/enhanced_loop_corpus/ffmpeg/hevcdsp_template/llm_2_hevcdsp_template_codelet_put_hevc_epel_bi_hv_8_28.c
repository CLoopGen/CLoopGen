#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int height;
extern int width;
extern int x;
extern int y;
extern uint8_t *src;
extern ptrdiff_t srcstride;
extern  int8_t *filter;
extern int16_t *tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with unrolled filtering (simulates vectorization-friendly pattern)
    for (y = 0; y < height + 3; y++) {
        int x4;
        for (x = 0; x < width - 3; x += 4) {
            tmp[x+0] = (filter[0] * src[(x+0) - 1] + filter[1] * src[x+0] + filter[2] * src[(x+0) + 1] + filter[3] * src[(x+0) + 2]) >> 0;
            tmp[x+1] = (filter[0] * src[(x+1) - 1] + filter[1] * src[x+1] + filter[2] * src[(x+1) + 1] + filter[3] * src[(x+1) + 2]) >> 0;
            tmp[x+2] = (filter[0] * src[(x+2) - 1] + filter[1] * src[x+2] + filter[2] * src[(x+2) + 1] + filter[3] * src[(x+2) + 2]) >> 0;
            tmp[x+3] = (filter[0] * src[(x+3) - 1] + filter[1] * src[x+3] + filter[2] * src[(x+3) + 1] + filter[3] * src[(x+3) + 2]) >> 0;
        }
        // Handle remaining elements
        for (; x < width; x++) {
            tmp[x] = (filter[0] * src[x - 1] + filter[1] * src[x] + filter[2] * src[x + 1] + filter[3] * src[x + 2]) >> 0;
        }
        src += srcstride;
        tmp += 64;
    }
}
