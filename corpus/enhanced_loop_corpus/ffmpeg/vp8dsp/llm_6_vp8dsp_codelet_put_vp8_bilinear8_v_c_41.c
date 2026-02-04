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
    int y, x;
    for (y = 0; y < h; y++) {
        uint8_t temp[8];
        for (x = 0; x < 8; x++)
            temp[x] = (c * src[x] + d * src[x + sstride] + 4) >> 3;
        for (x = 0; x < 8; x++)
            dst[x] = temp[x];
        dst += dstride;
        src += sstride;
    }
}
