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
        uint8_t *dst_local = dst;
        uint8_t *src_local = src;
        for (x = 0; x < 16; x++) {
            int val = (c * src_local[x] + d * src_local[x + sstride] + 4) >> 3;
            dst_local[x] = val;
        }
        dst += dstride;
        src += sstride;
    }
}
