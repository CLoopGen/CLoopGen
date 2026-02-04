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
    for (x = 0; x < 16; x += 2) {
        int val1 = src[x];
        int val2 = src[x + sstride];
        int val3 = src[x + 1];
        int val4 = src[x + 1 + sstride];
        dst[x]     = (c * val1 + d * val2 + 8) >> 4;
        dst[x + 1] = (c * val3 + d * val4 + 8) >> 4;
    }
    dst += dstride;
    src += sstride;
}
}
