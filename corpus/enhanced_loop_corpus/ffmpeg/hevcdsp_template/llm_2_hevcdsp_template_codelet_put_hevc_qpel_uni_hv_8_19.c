#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int height;
extern int width;
extern int x;
extern int y;
extern  int8_t *filter;
extern uint8_t *src;
extern ptrdiff_t srcstride;
extern int16_t *tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with unrolled filter application
    // Instead of accessing src with variable offsets, pre-load a local window buffer for spatial locality
    int8_t window[8];
    for (y = 0; y < height + 7; y++) {
        for (x = 0; x < width; x++) {
            // Load filter-sized window consecutively into local array to improve cache behavior
            window[0] = src[x - 3];
            window[1] = src[x - 2];
            window[2] = src[x - 1];
            window[3] = src[x];
            window[4] = src[x + 1];
            window[5] = src[x + 2];
            window[6] = src[x + 3];
            window[7] = src[x + 4];

            tmp[x] = (
                filter[0] * window[0] +
                filter[1] * window[1] +
                filter[2] * window[2] +
                filter[3] * window[3] +
                filter[4] * window[4] +
                filter[5] * window[5] +
                filter[6] * window[6] +
                filter[7] * window[7]
            ) >> (8 - 8);
        }
        src += srcstride;
        tmp += 64;
    }
}
