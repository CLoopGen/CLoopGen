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
    for (x = 0; x < 8; x++) {
        int cur = src[x];
        int next_line = src[x + sstride];
        int second_next = (y + 1 < h) ? src[x + 2*sstride] : next_line;
        dst[x] = (3 * c * cur + 2 * d * next_line + 5) >> 3;
        if (y + 1 < h)
            dst[x + dstride] = (c * next_line + 3 * d * second_next + 5) >> 3;
    }
    dst += 2 * dstride;
    src += 2 * sstride;
}
}
