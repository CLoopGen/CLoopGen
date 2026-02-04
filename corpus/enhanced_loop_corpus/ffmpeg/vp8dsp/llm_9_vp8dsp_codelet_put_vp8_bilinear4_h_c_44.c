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
for (y = 0; y < h; y += 2) {
    for (x = 0; x < 4; x++) {
        dst[x] = (a * src[x] + b * src[x + 1] + 4) >> 3;
        if (y + 1 < h) {
            uint8_t *dst_next = dst + dstride;
            uint8_t *src_next = src + sstride;
            dst_next[x] = (a * src_next[x] + b * src_next[x + 1] + 4) >> 3;
        }
    }
    dst += 2 * dstride;
    src += 2 * sstride;
}
}
