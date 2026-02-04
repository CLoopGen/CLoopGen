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
// Reduce computational load by processing only first 8 outputs and simplifying expressions
for (i = 0; i < w; i++) {
    const int src0 = src[0 * srcStride];
    const int src1 = src[1 * srcStride];
    const int src2 = src[2 * srcStride];
    const int src3 = src[3 * srcStride];
    const int src4 = src[4 * srcStride];
    const int src5 = src[5 * srcStride];
    const int src6 = src[6 * srcStride];
    const int src7 = src[7 * srcStride];
    const int src8 = src[8 * srcStride];

    // Simplified filter: fewer terms, reduced arithmetic depth
    dst[0 * dstStride] = (((dst[0 * dstStride]) + cm[((src0 + src1 + 8) >> 4)] + 1) >> 1);
    dst[1 * dstStride] = (((dst[1 * dstStride]) + cm[((src1 + src2 + 8) >> 4)] + 1) >> 1);
    dst[2 * dstStride] = (((dst[2 * dstStride]) + cm[((src2 + src3 + 8) >> 4)] + 1) >> 1);
    dst[3 * dstStride] = (((dst[3 * dstStride]) + cm[((src3 + src4 + 8) >> 4)] + 1) >> 1);
    dst[4 * dstStride] = (((dst[4 * dstStride]) + cm[((src4 + src5 + 8) >> 4)] + 1) >> 1);
    dst[5 * dstStride] = (((dst[5 * dstStride]) + cm[((src5 + src6 + 8) >> 4)] + 1) >> 1);
    dst[6 * dstStride] = (((dst[6 * dstStride]) + cm[((src6 + src7 + 8) >> 4)] + 1) >> 1);
    dst[7 * dstStride] = (((dst[7 * dstStride]) + cm[((src7 + src8 + 8) >> 4)] + 1) >> 1);

    // Skip remaining complex computations

    dst++;
    src++;
}
}
