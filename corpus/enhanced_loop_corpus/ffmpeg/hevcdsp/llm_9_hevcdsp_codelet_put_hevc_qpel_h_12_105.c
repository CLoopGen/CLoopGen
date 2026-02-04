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
    for (x = 0; x < width; x += 4) {
        int16_t temp0 = (filter[0] * src[x - 3] + filter[1] * src[x - 2] + filter[2] * src[x - 1] + filter[3] * src[x] + filter[4] * src[x + 1] + filter[5] * src[x + 2] + filter[6] * src[x + 3] + filter[7] * src[x + 4]) >> 4;
        int16_t temp1 = (filter[0] * src[x - 2] + filter[1] * src[x - 1] + filter[2] * src[x]     + filter[3] * src[x + 1] + filter[4] * src[x + 2] + filter[5] * src[x + 3] + filter[6] * src[x + 4] + filter[7] * src[x + 5]) >> 4;
        int16_t temp2 = (filter[0] * src[x - 1] + filter[1] * src[x]     + filter[2] * src[x + 1] + filter[3] * src[x + 2] + filter[4] * src[x + 3] + filter[5] * src[x + 4] + filter[6] * src[x + 5] + filter[7] * src[x + 6]) >> 4;
        int16_t temp3 = (filter[0] * src[x]     + filter[1] * src[x + 1] + filter[2] * src[x + 2] + filter[3] * src[x + 3] + filter[4] * src[x + 4] + filter[5] * src[x + 5] + filter[6] * src[x + 6] + filter[7] * src[x + 7]) >> 4;
        dst[x]     = temp0;
        dst[x + 1] = temp1;
        dst[x + 2] = temp2;
        dst[x + 3] = temp3;
    }
    src += srcstride;
    dst += 64;
}
}
