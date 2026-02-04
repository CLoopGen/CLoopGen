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
    const int baseIdx = i;
    const int offsets[] = {-2, -1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int srcVals[11];
    for (int j = 0; j < 11; j++) {
        srcVals[j] = src[baseIdx + offsets[j] * srcStride];
    }
    const int srcB = srcVals[0], srcA = srcVals[1], src0 = srcVals[2], src1 = srcVals[3],
                src2 = srcVals[4], src3 = srcVals[5], src4 = srcVals[6], src5 = srcVals[7],
                src6 = srcVals[8], src7 = srcVals[9], src8 = srcVals[10], src9 = srcVals[11],
                src10 = srcVals[12];
    dst[0 * dstStride] = ((dst[0 * dstStride]) + cm[((0 * srcB + -1 * srcA + 5 * src0 + 5 * src1 + -1 * src2 + 0 * src3) + 4) >> 3] + 1) >> 1;
    dst[1 * dstStride] = ((dst[1 * dstStride]) + cm[((0 * srcA + -1 * src0 + 5 * src1 + 5 * src2 + -1 * src3 + 0 * src4) + 4) >> 3] + 1) >> 1;
    dst[2 * dstStride] = ((dst[2 * dstStride]) + cm[((0 * src0 + -1 * src1 + 5 * src2 + 5 * src3 + -1 * src4 + 0 * src5) + 4) >> 3] + 1) >> 1;
    dst[3 * dstStride] = ((dst[3 * dstStride]) + cm[((0 * src1 + -1 * src2 + 5 * src3 + 5 * src4 + -1 * src5 + 0 * src6) + 4) >> 3] + 1) >> 1;
    dst[4 * dstStride] = ((dst[4 * dstStride]) + cm[((0 * src2 + -1 * src3 + 5 * src4 + 5 * src5 + -1 * src6 + 0 * src7) + 4) >> 3] + 1) >> 1;
    dst[5 * dstStride] = ((dst[5 * dstStride]) + cm[((0 * src3 + -1 * src4 + 5 * src5 + 5 * src6 + -1 * src7 + 0 * src8) + 4) >> 3] + 1) >> 1;
    dst[6 * dstStride] = ((dst[6 * dstStride]) + cm[((0 * src4 + -1 * src5 + 5 * src6 + 5 * src7 + -1 * src8 + 0 * src9) + 4) >> 3] + 1) >> 1;
    dst[7 * dstStride] = ((dst[7 * dstStride]) + cm[((0 * src5 + -1 * src6 + 5 * src7 + 5 * src8 + -1 * src9 + 0 * src10) + 4) >> 3] + 1) >> 1;
    dst++;
    src++;
}
}
