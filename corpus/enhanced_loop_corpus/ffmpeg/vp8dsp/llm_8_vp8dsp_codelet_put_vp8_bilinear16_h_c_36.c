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
    for (x = 0; x < 8; x++) {
        int val1 = (a * src[x] + b * src[x + 1] + 4) >> 3;
        int val2 = (a * src[x + 1] + b * src[x + 2] + 4) >> 3;
        dst[x] = val1;
        dst[x + 8] = val2;
    }
    dst += dstride;
    src += sstride;
}
}
