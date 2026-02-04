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
        for (x = 0; x < width; x++) {
            int16_t val1 = (filter[0] * src[x - 1] + filter[1] * src[x] + filter[2] * src[x + 1]) >> 2;
            int16_t val2 = (filter[1] * src[x] + filter[2] * src[x + 1] + filter[3] * src[x + 2]) >> 2;
            dst[x] = (val1 + val2) >> (10 - 8 - 1);
        }
        for (x = 0; x < width; x++) {
            dst[64 + x] = (filter[0] * src[x - 1 + srcstride] + filter[1] * src[x + srcstride] +
                           filter[2] * src[x + 1 + srcstride] + filter[3] * src[x + 2 + srcstride]) >> (10 - 8);
        }
        src += 2 * srcstride;
        dst += 2 * 64;
    }
}
