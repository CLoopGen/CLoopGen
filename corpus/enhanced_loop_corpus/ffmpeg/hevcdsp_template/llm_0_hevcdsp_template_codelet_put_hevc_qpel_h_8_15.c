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
        for (x = 0; x < width; x += 2) {
            dst[x] = (filter[0] * src[x - 3] + filter[1] * src[x - 2] + filter[2] * src[x - 1] + filter[3] * src[x] + filter[4] * src[x + 1] + filter[5] * src[x + 2] + filter[6] * src[x + 3] + filter[7] * src[x + 4]) >> 8;
            if (x + 1 < width) {
                dst[x + 1] = (filter[0] * src[x + 1 - 3] + filter[1] * src[x + 1 - 2] + filter[2] * src[x + 1 - 1] + filter[3] * src[x + 1] + filter[4] * src[x + 1 + 1] + filter[5] * src[x + 1 + 2] + filter[6] * src[x + 1 + 3] + filter[7] * src[x + 1 + 4]) >> 8;
            }
        }
        src += srcstride;
        dst += 64;
    }
}
