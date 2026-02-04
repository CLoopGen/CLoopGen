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
        uint8_t val = 0;
        for (x = 0; x < 16; x++) {
            val = (a * src[x] + b * src[x + 1] + 4) >> 3;
            dst[x] = val;
        }
        dst += dstride;
        src += sstride;
    }
}
