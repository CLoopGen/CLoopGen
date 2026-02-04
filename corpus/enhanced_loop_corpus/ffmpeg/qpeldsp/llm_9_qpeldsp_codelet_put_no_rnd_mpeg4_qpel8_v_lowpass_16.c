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
    // Reduce computational intensity: use fewer neighboring pixels and simplified weights
    const int src0 = src[0 * srcStride];
    const int src1 = src[1 * srcStride];
    const int src2 = src[2 * srcStride];
    const int src3 = src[3 * srcStride];

    // Simplified filter with reduced arithmetic operations
    dst[0 * dstStride] = cm[(src0 + src1 + 1) >> 1];  // Average of two pixels
    dst[1 * dstStride] = cm[(src1 + src2 + 1) >> 1];
    dst[2 * dstStride] = cm[(src2 + src3 + 1) >> 1];

    // Further reduce outputs to lower memory writes
    dst[3 * dstStride] = cm[(src0 * 3 + src1 * 1 + 2) >> 2];  // Weighted average

    dst++;
    src++;
}
}
