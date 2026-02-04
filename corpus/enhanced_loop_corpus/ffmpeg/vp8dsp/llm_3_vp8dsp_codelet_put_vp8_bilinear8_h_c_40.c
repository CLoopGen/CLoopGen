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
    uint8_t *src_offset = src + y * sstride;
    uint8_t *dst_offset = dst + y * dstride;
    for (x = 0; x < 8; x++) {
        int idx = (x & ~1) + ((x + 1) & 1); // Interleave access: 0->1, 1->0, 2->3, 3->2, etc.
        dst_offset[x] = (a * src_offset[idx] + b * src_offset[idx + 1] + 4) >> 3;
    }
}
}
