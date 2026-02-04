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
    for (x = 0; x < 4; x++) {
        int val1 = filter[2] * src[x + 0 * srcstride] - filter[1] * src[x - 1 * srcstride];
        int val2 = filter[3] * src[x + 1 * srcstride] - filter[4] * src[x + 2 * srcstride];
        dst[x*2+0] = cm[(val1 + val2 + 32) >> 6];
        dst[x*2+1] = cm[(val1 + val2 + 96) >> 6];
    }
    dst += dststride;
    src += srcstride;
}
}
