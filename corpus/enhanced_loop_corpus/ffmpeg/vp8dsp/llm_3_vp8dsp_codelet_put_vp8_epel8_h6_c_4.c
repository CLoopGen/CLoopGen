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
    for (x = 7; x >= 0; x--) {
        int offset = x - 2;
        uint8_t val = cm[(
            filter[2] * src[offset + 2] -
            filter[1] * src[offset + 1] +
            filter[0] * src[offset + 0] +
            filter[3] * src[offset + 3] -
            filter[4] * src[offset + 4] +
            filter[5] * src[offset + 5] + 64) >> 7];
        dst[x] = val;
    }
    dst += dststride;
    src += srcstride;
}
}
