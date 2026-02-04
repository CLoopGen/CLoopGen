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
    if (h > 10 && y == h / 2) {
        for (x = 0; x < 8; x++)
            dst[x] = cm[(filter[2] * src[x] - filter[1] * src[x - 1] + filter[3] * src[x + 1] - filter[4] * src[x + 2] + 64) >> 7];
        for (; x < 16; x++)
            dst[x] = cm[(filter[3] * src[x + 1] - filter[2] * src[x] + filter[1] * src[x - 1] - filter[4] * src[x + 2] + 64) >> 7];
    } else {
        for (x = 0; x < 16; x++)
            dst[x] = cm[(filter[2] * src[x + 0] - filter[1] * src[x - 1] + filter[3] * src[x + 1] - filter[4] * src[x + 2] + 64) >> 7];
    }
    dst += dststride;
    src += srcstride;
}
}
