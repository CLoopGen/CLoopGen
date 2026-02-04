#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern ptrdiff_t dstride;
extern int h;
extern int c;
extern int d;
extern int x;
extern int y;
extern uint8_t *tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = 0; y < h; y++) {
    x = 0;
    dst[x] = (c * tmp[x] + d * tmp[x + 16] + 4) >> 3;
    x = 1;
    dst[x] = (c * tmp[x] + d * tmp[x + 16] + 4) >> 3;
    x = 2;
    dst[x] = (c * tmp[x] + d * tmp[x + 16] + 4) >> 3;
    x = 3;
    dst[x] = (c * tmp[x] + d * tmp[x + 16] + 4) >> 3;
    x = 4;
    dst[x] = (c * tmp[x] + d * tmp[x + 16] + 4) >> 3;
    x = 5;
    dst[x] = (c * tmp[x] + d * tmp[x + 16] + 4) >> 3;
    x = 6;
    dst[x] = (c * tmp[x] + d * tmp[x + 16] + 4) >> 3;
    x = 7;
    dst[x] = (c * tmp[x] + d * tmp[x + 16] + 4) >> 3;
    x = 8;
    dst[x] = (c * tmp[x] + d * tmp[x + 16] + 4) >> 3;
    x = 9;
    dst[x] = (c * tmp[x] + d * tmp[x + 16] + 4) >> 3;
    x = 10;
    dst[x] = (c * tmp[x] + d * tmp[x + 16] + 4) >> 3;
    x = 11;
    dst[x] = (c * tmp[x] + d * tmp[x + 16] + 4) >> 3;
    x = 12;
    dst[x] = (c * tmp[x] + d * tmp[x + 16] + 4) >> 3;
    x = 13;
    dst[x] = (c * tmp[x] + d * tmp[x + 16] + 4) >> 3;
    x = 14;
    dst[x] = (c * tmp[x] + d * tmp[x + 16] + 4) >> 3;
    x = 15;
    dst[x] = (c * tmp[x] + d * tmp[x + 16] + 4) >> 3;
    dst += dstride;
    tmp += 16;
}
}
