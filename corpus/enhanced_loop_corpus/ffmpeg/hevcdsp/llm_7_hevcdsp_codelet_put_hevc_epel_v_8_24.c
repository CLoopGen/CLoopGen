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
    for (y = 0; y < height; y++) {
        int16_t accum = 0;
        for (x = 0; x < width; x++) {
            if (x == 0) {
                int32_t center = filter[1] * src[x] +
                                 filter[0] * src[x - srcstride] +
                                 filter[2] * src[x + srcstride] +
                                 filter[3] * src[x + 2 * srcstride];
                dst[0] = (center) >> 8;
                accum = dst[0];
            } else {
                int32_t val = filter[1] * src[x] +
                              filter[0] * src[x - srcstride] +
                              filter[2] * src[x + srcstride] +
                              filter[3] * src[x + 2 * srcstride];
                dst[x] = (val + accum) >> 8;
                accum = dst[x];
            }
        }
        src += srcstride;
        dst += 64;
    }
}
