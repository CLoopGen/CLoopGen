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
    uint8_t *src_row = src;
    uint8_t *dst_row = dst;
    for (y = 0; y < h; y++) {
        uint8_t *src_ptr = src_row;
        uint8_t *dst_ptr = dst_row;
        // Unroll and access consecutive elements in a linearized manner
        for (x = 0; x < 8; x += 2) {
            dst_ptr[x]     = (c * src_ptr[x] + d * src_ptr[x + sstride] + 4) >> 3;
            if (x + 1 < 8)
                dst_ptr[x + 1] = (c * src_ptr[x + 1] + d * src_ptr[x + 1 + sstride] + 4) >> 3;
        }
        dst_row += dstride;
        src_row += sstride;
    }
}
