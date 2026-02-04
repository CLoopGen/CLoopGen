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
    for (x = 0; x < width; x += 2) {
        dst[x]     = (filter[3] * src[x] + filter[4] * src[x + srcstride]) >> (12 - 8);
        dst[x + 1] = (filter[2] * src[x - srcstride] + filter[5] * src[x + 2 * srcstride]) >> (12 - 8);
    }
    src += srcstride;
    dst += 64;
}
}
