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
    for (x = 0; x < 16; x++) {
        ptrdiff_t idx = x;
        ptrdiff_t idx_next = x + sstride;
        dst[idx] = (c * src[idx] + d * src[idx_next] + 4) >> 3;
    }
    dst += dstride;
    src += sstride;
}
}
