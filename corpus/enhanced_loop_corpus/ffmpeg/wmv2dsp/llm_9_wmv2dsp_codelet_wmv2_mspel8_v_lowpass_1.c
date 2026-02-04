#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  uint8_t *src;
extern int dstStride;
extern int srcStride;
extern int w;
extern  uint8_t *cm;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < w; i++) {
    const int src0 = src[0];
    const int src1 = src[srcStride];
    const int src2 = src[2 * srcStride];
    const int src3 = src[3 * srcStride];
    const int src4 = src[4 * srcStride];
    const int src5 = src[5 * srcStride];
    const int src6 = src[6 * srcStride];
    const int src7 = src[7 * srcStride];

    const int sum01 = src0 + src1;
    const int sum12 = src1 + src2;
    const int sum23 = src2 + src3;
    const int sum34 = src3 + src4;
    const int sum45 = src4 + src5;
    const int sum56 = src5 + src6;
    const int sum67 = src6 + src7;

    const int term0 = (9 * sum01 - (src[-srcStride] + src[2 * srcStride]) + 8) >> 4;
    const int term1 = (9 * sum12 - (src0 + src[3 * srcStride]) + 8) >> 4;
    const int term2 = (9 * sum23 - (src1 + src[4 * srcStride]) + 8) >> 4;
    const int term3 = (9 * sum34 - (src2 + src[5 * srcStride]) + 8) >> 4;
    const int term4 = (9 * sum45 - (src3 + src[6 * srcStride]) + 8) >> 4;
    const int term5 = (9 * sum56 - (src4 + src[7 * srcStride]) + 8) >> 4;
    const int term6 = (9 * sum67 - (src5 + src[8 * srcStride]) + 8) >> 4;
    const int term7 = (9 * (src[7 * srcStride] + src[8 * srcStride]) - (src6 + src[9 * srcStride]) + 8) >> 4;

    dst[0 * dstStride] = cm[term0];
    dst[1 * dstStride] = cm[term1];
    dst[2 * dstStride] = cm[term2];
    dst[3 * dstStride] = cm[term3];
    dst[4 * dstStride] = cm[term4];
    dst[5 * dstStride] = cm[term5];
    dst[6 * dstStride] = cm[term6];
    dst[7 * dstStride] = cm[term7];

    src++;
    dst++;
}
}
