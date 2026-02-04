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
    uint8_t *src_base = src + y * sstride;
    uint8_t *dst_base = dst + y * dstride;
    for (x = 0; x < 16; x++) {
        int idx = x;
        dst_base[idx] = (a * src_base[idx] + b * src_base[idx + 1] + 4) >> 3;
    }
}
}
