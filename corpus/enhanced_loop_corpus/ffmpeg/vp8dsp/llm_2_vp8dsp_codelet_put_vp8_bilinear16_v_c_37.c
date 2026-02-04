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
    uint8_t *dst_row = dst + y * dstride;
    uint8_t *src_row = src + y * sstride;
    for (x = 0; x < 16; x += 2) {
        dst_row[x]     = (c * src_row[x] + d * src_row[x + sstride] + 4) >> 3;
        dst_row[x + 1] = (c * src_row[x + 1] + d * src_row[x + 1 + sstride] + 4) >> 3;
    }
}
}
