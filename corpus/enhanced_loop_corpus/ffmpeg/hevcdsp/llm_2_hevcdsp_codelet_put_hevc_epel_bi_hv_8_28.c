#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int height;
extern int width;
extern int x;
extern int y;
extern uint8_t *src;
extern ptrdiff_t srcstride;
extern  int8_t *filter;
extern int16_t *tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = 0; y < height + 3; y++) {
    for (x = 0; x < width; x += 4) {
        int x1 = x, x2 = x+1, x3 = x+2, x4 = x+3;
        tmp[x1] = (filter[0] * src[x1 - 1] + filter[1] * src[x1] + filter[2] * src[x1 + 1] + filter[3] * src[x1 + 2]) >> 8;
        tmp[x2] = (filter[0] * src[x2 - 1] + filter[1] * src[x2] + filter[2] * src[x2 + 1] + filter[3] * src[x2 + 2]) >> 8;
        tmp[x3] = (filter[0] * src[x3 - 1] + filter[1] * src[x3] + filter[2] * src[x3 + 1] + filter[3] * src[x3 + 2]) >> 8;
        tmp[x4] = (filter[0] * src[x4 - 1] + filter[1] * src[x4] + filter[2] * src[x4 + 1] + filter[3] * src[x4 + 2]) >> 8;
    }
    src += srcstride;
    tmp += 64;
}
}
