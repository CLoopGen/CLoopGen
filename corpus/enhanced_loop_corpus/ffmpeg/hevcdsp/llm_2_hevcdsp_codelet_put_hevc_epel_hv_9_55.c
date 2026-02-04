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
    // Variant 1: Consecutive memory access with unrolled filter computation
    // Changed access pattern to process two elements at a time (semi-consecutive) and unroll part of the filter
    for (y = 0; y < height + 3; y++) {
        for (x = 0; x < width - 1; x += 2) {
            int offset = x;
            tmp[offset]     = (filter[0] * src[offset - 1] + filter[1] * src[offset] + 
                              filter[2] * src[offset + 1] + filter[3] * src[offset + 2]) >> 1;
            tmp[offset + 1] = (filter[0] * src[offset]     + filter[1] * src[offset + 1] + 
                              filter[2] * src[offset + 2] + filter[3] * src[offset + 3]) >> 1;
        }
        // Handle last element if width is odd
        if (x < width) {
            tmp[x] = (filter[0] * src[x - 1] + filter[1] * src[x] + 
                      filter[2] * src[x + 1] + filter[3] * src[x + 2]) >> 1;
        }
        src += srcstride;
        tmp += 64;
    }
}
