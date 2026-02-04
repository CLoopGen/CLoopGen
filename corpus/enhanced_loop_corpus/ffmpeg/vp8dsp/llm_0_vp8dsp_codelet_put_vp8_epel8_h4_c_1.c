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
    x = 0;
    dst[x] = cm[(filter[2] * src[x + 0 * 1] - filter[1] * src[x - 1 * 1] + filter[3] * src[x + 1 * 1] - filter[4] * src[x + 2 * 1] + 64) >> 7];
    x = 1;
    dst[x] = cm[(filter[2] * src[x + 0 * 1] - filter[1] * src[x - 1 * 1] + filter[3] * src[x + 1 * 1] - filter[4] * src[x + 2 * 1] + 64) >> 7];
    x = 2;
    dst[x] = cm[(filter[2] * src[x + 0 * 1] - filter[1] * src[x - 1 * 1] + filter[3] * src[x + 1 * 1] - filter[4] * src[x + 2 * 1] + 64) >> 7];
    x = 3;
    dst[x] = cm[(filter[2] * src[x + 0 * 1] - filter[1] * src[x - 1 * 1] + filter[3] * src[x + 1 * 1] - filter[4] * src[x + 2 * 1] + 64) >> 7];
    x = 4;
    dst[x] = cm[(filter[2] * src[x + 0 * 1] - filter[1] * src[x - 1 * 1] + filter[3] * src[x + 1 * 1] - filter[4] * src[x + 2 * 1] + 64) >> 7];
    x = 5;
    dst[x] = cm[(filter[2] * src[x + 0 * 1] - filter[1] * src[x - 1 * 1] + filter[3] * src[x + 1 * 1] - filter[4] * src[x + 2 * 1] + 64) >> 7];
    x = 6;
    dst[x] = cm[(filter[2] * src[x + 0 * 1] - filter[1] * src[x - 1 * 1] + filter[3] * src[x + 1 * 1] - filter[4] * src[x + 2 * 1] + 64) >> 7];
    x = 7;
    dst[x] = cm[(filter[2] * src[x + 0 * 1] - filter[1] * src[x - 1 * 1] + filter[3] * src[x + 1 * 1] - filter[4] * src[x + 2 * 1] + 64) >> 7];
    dst += dststride;
    src += srcstride;
}
}
