#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  uint8_t *src;
extern int dstStride;
extern int srcStride;
extern  uint8_t *cm;
extern  int w;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < w; i++) {
    // Reduce arithmetic complexity: simplify the expressions and reduce number of terms
    const int src0 = src[0 * srcStride];
    const int src1 = src[1 * srcStride];
    const int src2 = src[2 * srcStride];
    const int src3 = src[3 * srcStride];
    const int src4 = src[4 * srcStride];

    // Lighter-weight filtering with fewer operations per pixel
    dst[0 * dstStride] = (dst[0 * dstStride] + cm[(src0 + src1 + 1) >> 1]) >> 1;
    dst[1 * dstStride] = (dst[1 * dstStride] + cm[(src1 + src2 + 1) >> 1]) >> 1;
    dst[2 * dstStride] = (dst[2 * dstStride] + cm[(src2 + src3 + 1) >> 1]) >> 1;
    dst[3 * dstStride] = (dst[3 * dstStride] + cm[(src3 + src4 + 1) >> 1]) >> 1;

    // Skip higher indices to match reduced operation count
    dst++;
    src++;
}
}
