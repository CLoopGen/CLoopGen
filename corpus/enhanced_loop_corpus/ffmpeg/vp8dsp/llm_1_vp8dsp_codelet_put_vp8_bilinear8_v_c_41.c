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
    for (x = 0; x < 8; x++) {
        int offset = x;
        for (int inner = 0; inner < 1; inner++) {
            dst[offset] = (c * src[offset] + d * src[offset + sstride] + 4) >> 3;
        }
    }
    dst += dstride;
    src += sstride;
}
}
