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
    dst[0] = (c * src[0] + d * src[sstride] + 4) >> 3;
    dst[1] = (c * src[1] + d * src[1 + sstride] + 4) >> 3;
    dst[2] = (c * src[2] + d * src[2 + sstride] + 4) >> 3;
    dst[3] = (c * src[3] + d * src[3 + sstride] + 4) >> 3;
    dst += dstride;
    src += sstride;
}
}
