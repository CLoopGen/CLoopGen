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
    uint8_t *dst_row = dst + y * dstride;
    uint8_t *src_row = src + y * sstride;
    for (x = 0; x < 16; x += 2) {
        dst_row[x]   = (a * src_row[x] + b * src_row[x + 1] + 4) >> 3;
        if (x + 1 < 16)
            dst_row[x + 1] = (a * src_row[x + 1] + b * src_row[x + 2] + 4) >> 3;
    }
}
}
