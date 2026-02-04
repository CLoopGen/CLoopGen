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
    // Variant 1: Consecutive memory access with unrolled filter application
    // Instead of accessing src with scattered offsets, preload a local window and use consecutive indexing
    for (y = 0; y < height + 3; y++) {
        uint8_t window[4];
        for (x = 0; x < width; x++) {
            // Load neighborhood into a local array to promote consecutive access pattern
            window[0] = src[x - 1];
            window[1] = src[x];
            window[2] = src[x + 1];
            window[3] = src[x + 2];  // Note: original had "x + 2 * 1", simplified
            tmp[x] = (filter[0] * window[0] + filter[1] * window[1] + 
                      filter[2] * window[2] + filter[3] * window[3]) >> 8;
        }
        src += srcstride;
        tmp += 64;
    }
}
