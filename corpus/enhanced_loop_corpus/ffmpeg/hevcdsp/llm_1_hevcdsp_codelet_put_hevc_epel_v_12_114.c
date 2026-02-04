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
        dst[0] = (filter[0] * src[-srcstride] + filter[1] * src[0] + 
                  filter[2] * src[srcstride] + filter[3] * src[2 * srcstride]) >> 4;
        for (x = 1; x < width; x++) {
            dst[x] = (filter[0] * src[x - srcstride] + filter[1] * src[x] + 
                      filter[2] * src[x + srcstride] + filter[3] * src[x + 2 * srcstride]) >> 4;
        }
        src += srcstride;
        dst += 64;
    }
}
