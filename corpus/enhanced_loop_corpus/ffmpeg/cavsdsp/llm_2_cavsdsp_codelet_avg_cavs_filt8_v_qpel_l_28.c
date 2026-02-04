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
    // Variant 1: Consecutive Memory Access Pattern
    // Instead of strided access, preload src values into a local array with consecutive access
    int srcVals[13]; // Holds src[-2] to src[10]
    for (i = 0; i < w; i++) {
        // Preload required source values using strided access once
        for (int j = -2; j <= 10; j++) {
            srcVals[j + 2] = src[j * srcStride];
        }
        // Use consecutive accesses from srcVals
        dst[0 * dstStride] = ((dst[0 * dstStride]) + cm[((-1 * srcVals[0] + -2 * srcVals[1] + 96 * srcVals[2] + 42 * srcVals[3] + -7 * srcVals[4] + 0 * srcVals[5]) + 64) >> 7] + 1) >> 1;
        dst[1 * dstStride] = ((dst[1 * dstStride]) + cm[((-1 * srcVals[1] + -2 * srcVals[2] + 96 * srcVals[3] + 42 * srcVals[4] + -7 * srcVals[5] + 0 * srcVals[6]) + 64) >> 7] + 1) >> 1;
        dst[2 * dstStride] = ((dst[2 * dstStride]) + cm[((-1 * srcVals[2] + -2 * srcVals[3] + 96 * srcVals[4] + 42 * srcVals[5] + -7 * srcVals[6] + 0 * srcVals[7]) + 64) >> 7] + 1) >> 1;
        dst[3 * dstStride] = ((dst[3 * dstStride]) + cm[((-1 * srcVals[3] + -2 * srcVals[4] + 96 * srcVals[5] + 42 * srcVals[6] + -7 * srcVals[7] + 0 * srcVals[8]) + 64) >> 7] + 1) >> 1;
        dst[4 * dstStride] = ((dst[4 * dstStride]) + cm[((-1 * srcVals[4] + -2 * srcVals[5] + 96 * srcVals[6] + 42 * srcVals[7] + -7 * srcVals[8] + 0 * srcVals[9]) + 64) >> 7] + 1) >> 1;
        dst[5 * dstStride] = ((dst[5 * dstStride]) + cm[((-1 * srcVals[5] + -2 * srcVals[6] + 96 * srcVals[7] + 42 * srcVals[8] + -7 * srcVals[9] + 0 * srcVals[10]) + 64) >> 7] + 1) >> 1;
        dst[6 * dstStride] = ((dst[6 * dstStride]) + cm[((-1 * srcVals[6] + -2 * srcVals[7] + 96 * srcVals[8] + 42 * srcVals[9] + -7 * srcVals[10] + 0 * srcVals[11]) + 64) >> 7] + 1) >> 1;
        dst[7 * dstStride] = ((dst[7 * dstStride]) + cm[((-1 * srcVals[7] + -2 * srcVals[8] + 96 * srcVals[9] + 42 * srcVals[10] + -7 * srcVals[11] + 0 * srcVals[12]) + 64) >> 7] + 1) >> 1;
        dst++;
        src++;
    }
}
