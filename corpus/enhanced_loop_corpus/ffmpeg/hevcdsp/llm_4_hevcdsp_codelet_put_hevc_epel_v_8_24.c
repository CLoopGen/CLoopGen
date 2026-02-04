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
    if (y % 2 == 0) {
        for (x = 0; x < width; x++) {
            dst[x] = (filter[0] * src[x - srcstride] + filter[1] * src[x] + filter[2] * src[x + srcstride] + filter[3] * src[x + 2 * srcstride]) >> 8;
        }
    } else {
        for (x = 0; x < width; x++) {
            int16_t temp = (filter[0] * src[x - srcstride] + filter[1] * src[x] + filter[2] * src[x + srcstride] + filter[3] * src[x + 2 * srcstride]) >> 8;
            if (temp > 0) {
                dst[x] = temp;
            } else {
                dst[x] = 0;
            }
        }
    }
    src += srcstride;
    dst += 64;
}
}
