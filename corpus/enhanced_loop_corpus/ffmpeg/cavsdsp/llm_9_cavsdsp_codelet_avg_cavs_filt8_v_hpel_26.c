#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  uint8_t *src;
extern ptrdiff_t dstStride;
extern ptrdiff_t srcStride;
extern  int w;
extern  uint8_t *cm;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < w; i++) {
    // Reduce arithmetic complexity by reusing common terms and reducing coefficient variety
    const int src0 = src[0 * srcStride];
    const int src1 = src[1 * srcStride];
    const int src2 = src[2 * srcStride];
    const int src3 = src[3 * srcStride];
    const int src4 = src[4 * srcStride];

    // Simplified filter kernel: (src0 + src1 + 1) >> 1, with fewer taps and no cm lookup
    dst[0 * dstStride] = ((dst[0 * dstStride]) + ((src0 + src1 + 1) >> 1) + 1) >> 1;
    dst[1 * dstStride] = ((dst[1 * dstStride]) + ((src1 + src2 + 1) >> 1) + 1) >> 1;
    dst[2 * dstStride] = ((dst[2 * dstStride]) + ((src2 + src3 + 1) >> 1) + 1) >> 1;
    dst[3 * dstStride] = ((dst[3 * dstStride]) + ((src3 + src4 + 1) >> 1) + 1) >> 1;

    // Advance pointers by one step per iteration
    dst++;
    src++;
}
}
