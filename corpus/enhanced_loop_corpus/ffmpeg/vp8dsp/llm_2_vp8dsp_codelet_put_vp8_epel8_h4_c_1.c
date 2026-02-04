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
    for (x = 0; x < 8; x++)
        temp[x] = src[x + 1] - src[x - 1];
    for (x = 0; x < 8; x++)
        dst[x] = cm[(filter[2] * temp[x] + filter[3] * temp[x + 1] - filter[1] * temp[x - 1] - filter[4] * temp[x + 2] + 64) >> 7];
    dst += dststride;
    src += srcstride;
}
}
