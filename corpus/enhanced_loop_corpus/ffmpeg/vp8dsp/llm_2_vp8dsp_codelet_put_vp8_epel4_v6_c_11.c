#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern ptrdiff_t dststride;
extern uint8_t *src;
extern ptrdiff_t srcstride;
extern int h;
extern  uint8_t *filter;
extern  uint8_t *cm;
extern int x;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with unrolled accumulation
    // Instead of accessing src with varying offsets in a single expression,
    // we precompute base pointers and access consecutive elements for better locality.
    uint8_t *src0, *src1, *src2, *src3, *src4, *src5;
    for (y = 0; y < h; y++) {
        src0 = &src[0 * srcstride];
        src1 = &src[-1 * srcstride];
        src2 = &src[-2 * srcstride];
        src3 = &src[1 * srcstride];
        src4 = &src[2 * srcstride];
        src5 = &src[3 * srcstride];
        for (x = 0; x < 4; x++) {
            int sum = filter[2] * src0[x] - filter[1] * src1[x] + filter[0] * src2[x]
                    + filter[3] * src3[x] - filter[4] * src4[x] + filter[5] * src5[x];
            dst[x] = cm[(sum + 64) >> 7];
        }
        dst += dststride;
        src += srcstride;
    }
}
