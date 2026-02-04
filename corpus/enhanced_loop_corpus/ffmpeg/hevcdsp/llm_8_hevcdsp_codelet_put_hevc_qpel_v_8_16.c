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
for (y = 0; y < height; y += 2) {
    for (x = 0; x < width; x++) {
        int16_t sum1 = (filter[0] * src[x - 3 * srcstride] + filter[1] * src[x - 2 * srcstride] + 
                        filter[2] * src[x - srcstride] + filter[3] * src[x]) >> 8;
        int16_t sum2 = (filter[4] * src[x + srcstride] + filter[5] * src[x + 2 * srcstride] + 
                        filter[6] * src[x + 3 * srcstride] + filter[7] * src[x + 4 * srcstride]) >> 8;
        dst[x] = (sum1 + sum2) << 8;
    }
    for (x = 0; x < width; x++) {
        int16_t sum = (filter[0] * src[x + srcstride - 3 * srcstride] + filter[1] * src[x + srcstride - 2 * srcstride] + 
                       filter[2] * src[x + srcstride - srcstride] + filter[3] * src[x + srcstride] + 
                       filter[4] * src[x + srcstride + srcstride] + filter[5] * src[x + srcstride + 2 * srcstride] + 
                       filter[6] * src[x + srcstride + 3 * srcstride] + filter[7] * src[x + srcstride + 4 * srcstride]) >> (8 - 8);
        dst[x + 64] = sum;
    }
    src += 2 * srcstride;
    dst += 128;
}
}
