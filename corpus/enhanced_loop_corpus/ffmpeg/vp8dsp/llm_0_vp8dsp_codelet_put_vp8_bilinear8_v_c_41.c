#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern ptrdiff_t dstride;
extern uint8_t *src;
extern ptrdiff_t sstride;
extern int h;
extern int c;
extern int d;
extern int x;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = 0; y < h; y++) {
    x = 0;
    dst[x] = (c * src[x] + d * src[x + sstride] + 4) >> 3;
    x = 1;
    dst[x] = (c * src[x] + d * src[x + sstride] + 4) >> 3;
    x = 2;
    dst[x] = (c * src[x] + d * src[x + sstride] + 4) >> 3;
    x = 3;
    dst[x] = (c * src[x] + d * src[x + sstride] + 4) >> 3;
    x = 4;
    dst[x] = (c * src[x] + d * src[x + sstride] + 4) >> 3;
    x = 5;
    dst[x] = (c * src[x] + d * src[x + sstride] + 4) >> 3;
    x = 6;
    dst[x] = (c * src[x] + d * src[x + sstride] + 4) >> 3;
    x = 7;
    dst[x] = (c * src[x] + d * src[x + sstride] + 4) >> 3;
    dst += dstride;
    src += sstride;
}
}
