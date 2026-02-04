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
            dst[x]     = (filter[0] * src[x - srcstride] + filter[1] * src[x] + 
                          filter[2] * src[x + srcstride]) >> 4;
            dst[x + 1] = (filter[1] * src[x + 1 - srcstride] + filter[2] * src[x + 1] + 
                          filter[3] * src[x + 1 + srcstride]) >> 4;
        }
        src += srcstride;
        dst += 64;
    }
}
