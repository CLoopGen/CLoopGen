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
for (y = 0; y < h; y += 2) {
    if (y + 1 < h) {
        for (x = 0; x < 16; x++) {
            dst[x]                    = (c * src[x] + d * src[x + sstride] + 4) >> 3;
            dst[x + dstride]          = (c * src[x + sstride] + d * src[x + 2*sstride] + 4) >> 3;
        }
        dst += 2 * dstride;
        src += 2 * sstride;
    } else {
        for (x = 0; x < 16; x++)
            dst[x] = (c * src[x] + d * src[x + sstride] + 4) >> 3;
        dst += dstride;
        src += sstride;
    }
}
}
