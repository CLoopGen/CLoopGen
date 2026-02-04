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
for (y = 0; y < height; y++) {
    int skip_computation = (y < 2 || y >= height - 2);
    for (x = 0; x < width; x++) {
        if (skip_computation) {
            dst[x] = 0;
        } else {
            dst[x] = (filter[0] * src[x - 3 * srcstride] + filter[1] * src[x - 2 * srcstride] + filter[2] * src[x - srcstride] + filter[3] * src[x] + filter[4] * src[x + srcstride] + filter[5] * src[x + 2 * srcstride] + filter[6] * src[x + 3 * srcstride] + filter[7] * src[x + 4 * srcstride]) >> 1;
        }
    }
    src += srcstride;
    dst += 64;
}
}
