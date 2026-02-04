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
    if (h <= 0) return;
    for (y = 0; y < h; y++) {
        int x = 0;
        if (a == 0) {
            for (; x < 4; x++)
                dst[x] = (b * src[x + 1] + 4) >> 3;
        } else if (b == 0) {
            for (; x < 4; x++)
                dst[x] = (a * src[x] + 4) >> 3;
        } else {
            for (; x < 4; x++)
                dst[x] = (a * src[x] + b * src[x + 1] + 4) >> 3;
        }
        dst += dstride;
        src += sstride;
    }
}
