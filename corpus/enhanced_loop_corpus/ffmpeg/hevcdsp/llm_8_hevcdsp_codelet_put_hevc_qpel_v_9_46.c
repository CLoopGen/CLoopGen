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
for (y = 0; y < height; y += 2) {
    for (x = 0; x < width; x++)
        dst[x] = (filter[0] * src[x - 2 * srcstride] + filter[1] * src[x - srcstride] + filter[2] * src[x] + filter[3] * src[x + srcstride] + filter[4] * src[x + 2 * srcstride]) >> 1;
    for (x = 0; x < width; x++)
        dst[64 + x] = (filter[0] * (src + srcstride)[x - 2 * srcstride] + filter[1] * (src + srcstride)[x - srcstride] + filter[2] * (src + srcstride)[x] + filter[3] * (src + srcstride)[x + srcstride] + filter[4] * (src + srcstride)[x + 2 * srcstride]) >> 1;
    src += 2 * srcstride;
    dst += 128;
}
}
