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
        for (x = 0; x < 16; x++) {
            int temp = a * src[x] + b * src[x + 1];
            if (temp > 0)
                dst[x] = (temp + 4) >> 3;
            else
                dst[x] = 0;
        }
        dst += dstride;
        src += sstride;
    }
}
