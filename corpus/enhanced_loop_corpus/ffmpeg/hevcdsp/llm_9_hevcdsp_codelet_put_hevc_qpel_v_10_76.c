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
    if (width >= 8) {
        for (x = 0; x < width - 7; x += 8) {
            for (int offset = 0; offset < 8; offset++) {
                dst[x + offset] = (filter[0] * src[(x + offset) - 3 * srcstride] + 
                                   filter[1] * src[(x + offset) - 2 * srcstride] + 
                                   filter[2] * src[(x + offset) - srcstride] + 
                                   filter[3] * src[(x + offset)] + 
                                   filter[4] * src[(x + offset) + srcstride] + 
                                   filter[5] * src[(x + offset) + 2 * srcstride] + 
                                   filter[6] * src[(x + offset) + 3 * srcstride] + 
                                   filter[7] * src[(x + offset) + 4 * srcstride]) >> (10 - 8);
            }
        }
        for (; x < width; x++) {
            dst[x] = (filter[0] * src[x - 3 * srcstride] + 
                      filter[1] * src[x - 2 * srcstride] + 
                      filter[2] * src[x - srcstride] + 
                      filter[3] * src[x] + 
                      filter[4] * src[x + srcstride] + 
                      filter[5] * src[x + 2 * srcstride] + 
                      filter[6] * src[x + 3 * srcstride] + 
                      filter[7] * src[x + 4 * srcstride]) >> (10 - 8);
        }
    } else {
        for (x = 0; x < width; x++) {
            dst[x] = (filter[0] * src[x - 3 * srcstride] + 
                      filter[1] * src[x - 2 * srcstride] + 
                      filter[2] * src[x - srcstride] + 
                      filter[3] * src[x] + 
                      filter[4] * src[x + srcstride] + 
                      filter[5] * src[x + 2 * srcstride] + 
                      filter[6] * src[x + 3 * srcstride] + 
                      filter[7] * src[x + 4 * srcstride]) >> (10 - 8);
        }
    }
    src += srcstride;
    dst += 64;
}
}
