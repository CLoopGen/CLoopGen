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
        x = 0;
        dst[0] = (filter[0] * src[-1] + filter[1] * src[0] + filter[2] * src[1] + filter[3] * src[2]) >> 1;
        for (x = 1; x < width - 1; x++) {
            dst[x] = (filter[0] * src[x - 1] + filter[1] * src[x] + filter[2] * src[x + 1] + filter[3] * src[x + 2]) >> 1;
        }
        if (width > 1) {
            dst[width - 1] = (filter[0] * src[width - 2] + filter[1] * src[width - 1] + 
                              filter[2] * src[width] + filter[3] * src[width + 1]) >> 1;
        }
        src += srcstride;
        dst += 64;
    }
}
