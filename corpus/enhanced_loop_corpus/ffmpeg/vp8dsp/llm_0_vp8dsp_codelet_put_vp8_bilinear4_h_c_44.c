#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern ptrdiff_t dstride;
extern uint8_t *src;
extern ptrdiff_t sstride;
extern int h;
extern int a;
extern int b;
extern int x;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = 0; y < h; y++) {
    x = 0;
    dst[x] = (a * src[x] + b * src[x + 1] + 4) >> 3;
    x = 1;
    dst[x] = (a * src[x] + b * src[x + 1] + 4) >> 3;
    x = 2;
    dst[x] = (a * src[x] + b * src[x + 1] + 4) >> 3;
    x = 3;
    dst[x] = (a * src[x] + b * src[x + 1] + 4) >> 3;
    dst += dstride;
    src += sstride;
}
}
