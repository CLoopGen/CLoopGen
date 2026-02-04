#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int w;
extern ptrdiff_t ds;
extern int mxy;
extern int avg;
extern uint8_t *dst;
extern  uint8_t *src;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with step size 2 (unrolling-like pattern)
    // Access every second element in both src and dst, then handle remaining elements
    int stride = 2;
    int limit = (w / stride) * stride;

    for (x = 0; x < limit; x += stride) {
        if (avg) {
            dst[x] = (dst[x] + (src[x] + ((mxy * (src[x + ds] - src[x]) + 8) >> 4)) + 1) >> 1;
            dst[x + 1] = (dst[x + 1] + (src[x + 1] + ((mxy * (src[x + 1 + ds] - src[x + 1]) + 8) >> 4)) + 1) >> 1;
        } else {
            dst[x] = (src[x] + ((mxy * (src[x + ds] - src[x]) + 8) >> 4));
            dst[x + 1] = (src[x + 1] + ((mxy * (src[x + 1 + ds] - src[x + 1]) + 8) >> 4));
        }
    }

    // Handle leftover element if w is odd
    if (limit < w) {
        x = limit;
        if (avg) {
            dst[x] = (dst[x] + (src[x] + ((mxy * (src[x + ds] - src[x]) + 8) >> 4)) + 1) >> 1;
        } else {
            dst[x] = (src[x] + ((mxy * (src[x + ds] - src[x]) + 8) >> 4));
        }
    }
}
