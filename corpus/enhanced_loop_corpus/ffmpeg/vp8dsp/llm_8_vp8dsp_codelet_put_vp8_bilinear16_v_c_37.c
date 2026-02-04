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
    for (x = 0; x < 8; x++) {
        int val1 = src[x] + src[x + sstride];
        int val2 = src[x + 1] - src[x + sstride + 1];
        dst[x*2]     = (c * val1 + 3) >> 2;
        dst[x*2 + 1] = (d * val2 + 5) >> 3;
    }
    dst += dstride;
    src += sstride;
}
}
