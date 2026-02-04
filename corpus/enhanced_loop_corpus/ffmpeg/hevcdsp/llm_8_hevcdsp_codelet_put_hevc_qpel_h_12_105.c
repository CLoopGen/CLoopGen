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
        dst[x] = (filter[0] * src[x - 3] + filter[1] * src[x - 2] + filter[2] * src[x - 1] + filter[3] * src[x] + filter[4] * src[x + 1] + filter[5] * src[x + 2] + filter[6] * src[x + 3] + filter[7] * src[x + 4]) >> 4;
    for (x = 0; x < width; x++)
        dst[x + 64] = (filter[0] * src[x - 3 + srcstride] + filter[1] * src[x - 2 + srcstride] + filter[2] * src[x - 1 + srcstride] + filter[3] * src[x + srcstride] + filter[4] * src[x + 1 + srcstride] + filter[5] * src[x + 2 + srcstride] + filter[6] * src[x + 3 + srcstride] + filter[7] * src[x + 4 + srcstride]) >> 4;
    src += 2 * srcstride;
    dst += 128;
}
}
