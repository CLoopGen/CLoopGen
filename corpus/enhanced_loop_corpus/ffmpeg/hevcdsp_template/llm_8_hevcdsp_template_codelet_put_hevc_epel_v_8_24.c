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
            int16_t val1 = (filter[0] * src[x - srcstride] + filter[1] * src[x] + filter[2] * src[x + srcstride]) >> 8;
            dst[x] = val1;
            if (y + 1 < height) {
                int16_t val2 = (filter[0] * src[x + srcstride] + filter[1] * src[x + 2*srcstride] + filter[2] * src[x + 3*srcstride]) >> 8;
                dst[x + 64] = val2;
            }
        }
        src += 2 * srcstride;
        dst += 128;
    }
}
