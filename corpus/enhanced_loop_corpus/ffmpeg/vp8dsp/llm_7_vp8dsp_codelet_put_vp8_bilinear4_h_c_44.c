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
        uint8_t val0 = (a * src[0] + b * src[1] + 4) >> 3;
        uint8_t val1 = (a * src[1] + b * src[2] + 4) >> 3;
        uint8_t val2 = (a * src[2] + b * src[3] + 4) >> 3;
        uint8_t val3 = (a * src[3] + b * src[4] + 4) >> 3;
        dst[0] = val0;
        dst[1] = val1;
        dst[2] = val2;
        dst[3] = val3;
        dst += dstride;
        src += sstride;
    }
}
