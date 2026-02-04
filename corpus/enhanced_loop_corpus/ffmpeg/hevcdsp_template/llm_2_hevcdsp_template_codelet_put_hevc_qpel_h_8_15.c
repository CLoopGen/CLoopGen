#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *dst;
extern int height;
extern int width;
extern int x;
extern int y;
extern uint8_t *src;
extern ptrdiff_t srcstride;
extern  int8_t *filter;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with manual pointer arithmetic unrolling for better spatial locality
    for (y = 0; y < height; y++) {
        const uint8_t *s = src;
        int16_t *d = dst;
        for (x = 0; x < width; x++) {
            const uint8_t *p = &s[x];
            d[x] = (int16_t)(
                filter[0] * p[-3] +
                filter[1] * p[-2] +
                filter[2] * p[-1] +
                filter[3] * p[0] +
                filter[4] * p[1] +
                filter[5] * p[2] +
                filter[6] * p[3] +
                filter[7] * p[4]
            ) >> (8 - 8);
        }
        src += srcstride;
        dst += 64;
    }
}
