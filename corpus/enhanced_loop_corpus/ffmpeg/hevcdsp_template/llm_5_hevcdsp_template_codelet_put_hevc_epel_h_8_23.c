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
    for (x = 0; x < width; x++) {
        int val;
        if (x < width / 2) {
            val = (filter[0] * src[x - 1] + filter[1] * src[x] + filter[2] * src[x + 1] + filter[3] * src[x + 2]) >> 8;
        } else {
            val = (filter[1] * src[x - 1] + filter[0] * src[x] + filter[3] * src[x + 1] + filter[2] * src[x + 2]) >> 8;
        }
        dst[x] = val;
    }
    src += srcstride;
    dst += 64;
}
}
