#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern ptrdiff_t dststride;
extern uint8_t *src;
extern ptrdiff_t srcstride;
extern int h;
extern  uint8_t *filter;
extern  uint8_t *cm;
extern int x;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = 0; y < h; y++) {
    uint8_t temp[8];
    for (x = 0; x < 8; x++) {
        int index = x * srcstride;
        temp[x] = cm[(filter[2] * src[index + 0] - filter[1] * src[index - srcstride] + filter[0] * src[index - 2*srcstride] + filter[3] * src[index + srcstride] - filter[4] * src[index + 2*srcstride] + filter[5] * src[index + 3*srcstride] + 64) >> 7];
    }
    for (x = 0; x < 8; x++) {
        dst[x] = temp[x];
    }
    dst += dststride;
    src += srcstride;
}
}
