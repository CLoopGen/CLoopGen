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
    // Variant 1: Consecutive memory access with pointer arithmetic unrolling
    uint8_t *src0 = src;
    uint8_t *dst0 = dst;
    for (y = 0; y < h; y++) {
        dst0[0] = (c * src0[0] + d * src0[sstride] + 4) >> 3;
        dst0[1] = (c * src0[1] + d * src0[sstride + 1] + 4) >> 3;
        dst0[2] = (c * src0[2] + d * src0[sstride + 2] + 4) >> 3;
        dst0[3] = (c * src0[3] + d * src0[sstride + 3] + 4) >> 3;
        dst0 += dstride;
        src0 += sstride;
    }
}
