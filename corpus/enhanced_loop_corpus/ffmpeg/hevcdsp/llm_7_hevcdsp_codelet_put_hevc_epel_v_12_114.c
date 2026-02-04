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
    int offset;
    for (y = 0; y < height; y++) {
        offset = y * srcstride;
        for (x = 0; x < width; x++) {
            dst[x] = (filter[0] * src[offset + x - srcstride] +
                      filter[1] * src[offset + x] +
                      filter[2] * src[offset + x + srcstride] +
                      filter[3] * src[offset + x + 2 * srcstride]) >> 4;
        }
        dst += 64;
    }
}
