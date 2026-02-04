#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *dst;
extern int height;
extern int width;
extern int x;
extern int y;
extern uint16_t *src;
extern ptrdiff_t srcstride;
extern  int8_t *filter;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with manual offset adjustment
    // Instead of relying on negative and positive strides around x, we precompute base pointers
    // to enable more sequential-looking access patterns for src, improving cache locality.

    int16_t *dst_base = dst;
    uint16_t *src_top = src - srcstride; // Pre-offset to avoid negative indexing in filter[0]

    for (y = 0; y < height; y++) {
        uint16_t *s = src_top + y * srcstride;
        int16_t *d = dst_base + y * 64;

        for (x = 0; x < width; x++) {
            d[x] = (filter[0] * s[x] +
                    filter[1] * s[x + srcstride] +
                    filter[2] * s[x + 2 * srcstride] +
                    filter[3] * s[x + 3 * srcstride]) >> 1;
        }
    }
}
