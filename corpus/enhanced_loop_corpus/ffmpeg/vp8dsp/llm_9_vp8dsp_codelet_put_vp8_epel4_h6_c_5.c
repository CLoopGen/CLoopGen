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
for (y = 0; y < h; y += 2) {
    for (x = 0; x < 2; x++) {
        dst[x] = cm[(filter[0] * src[x - 2] + filter[2] * src[x] + filter[3] * src[x + 1] + 64) >> 7];
    }
    dst += dststride;
    src += srcstride;
    if (y + 1 < h) {
        dst += dststride;
        src += srcstride;
    }
}
}
