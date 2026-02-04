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
        int offset = y * srcstride;
        for (x = 0; x < width; x++) {
            int idx = offset + x;
            dst[x] = (filter[0] * src[idx - srcstride] + filter[1] * src[idx] + 
                      filter[2] * src[idx + srcstride] + filter[3] * src[idx + 2 * srcstride]) >> 8;
        }
        src += srcstride;
        dst += 64;
    }
}
