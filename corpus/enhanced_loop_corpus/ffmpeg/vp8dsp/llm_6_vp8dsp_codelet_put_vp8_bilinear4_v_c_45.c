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
    int t0, t1, t2, t3;
    for (y = 0; y < h; y++) {
        t0 = (c * src[0] + d * src[sstride] + 4) >> 3;
        t1 = (c * src[1] + d * src[sstride + 1] + 4) >> 3;
        t2 = (c * src[2] + d * src[sstride + 2] + 4) >> 3;
        t3 = (c * src[3] + d * src[sstride + 3] + 4) >> 3;
        dst[0] = t0;
        dst[1] = t1;
        dst[2] = t2;
        dst[3] = t3;
        dst += dstride;
        src += sstride;
    }
}
