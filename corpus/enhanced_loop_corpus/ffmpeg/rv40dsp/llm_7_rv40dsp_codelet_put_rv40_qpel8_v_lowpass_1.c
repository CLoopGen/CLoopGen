#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  uint8_t *src;
extern int dstStride;
extern int srcStride;
extern  int w;
extern  int C1;
extern  int C2;
extern  int SHIFT;
extern  uint8_t *cm;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < w; i++) {
    const int srcB = src[-2 * srcStride];
    const int srcA = src[-1 * srcStride];
    const int src0 = src[0 * srcStride];
    const int src1 = src[1 * srcStride];
    const int src2 = src[2 * srcStride];
    const int src3 = src[3 * srcStride];
    const int src4 = src[4 * srcStride];
    const int src5 = src[5 * srcStride];
    const int src6 = src[6 * srcStride];
    const int src7 = src[7 * srcStride];
    const int src8 = src[8 * srcStride];
    const int src9 = src[9 * srcStride];
    const int src10 = src[10 * srcStride];

    int sum_prev, sum_curr, result;

    sum_prev = srcB + src3;
    sum_curr = srcA + src2;
    result = (sum_prev - 5 * sum_curr + src0 * C1 + src1 * C2 + (1 << (SHIFT - 1))) >> SHIFT;
    dst[0 * dstStride] = cm[result];

    sum_prev = srcA + src4;
    sum_curr = src0 + src3;
    result = (sum_prev - 5 * sum_curr + src1 * C1 + src2 * C2 + (1 << (SHIFT - 1))) >> SHIFT;
    dst[1 * dstStride] = cm[result];

    sum_prev = src0 + src5;
    sum_curr = src1 + src4;
    result = (sum_prev - 5 * sum_curr + src2 * C1 + src3 * C2 + (1 << (SHIFT - 1))) >> SHIFT;
    dst[2 * dstStride] = cm[result];

    sum_prev = src1 + src6;
    sum_curr = src2 + src5;
    result = (sum_prev - 5 * sum_curr + src3 * C1 + src4 * C2 + (1 << (SHIFT - 1))) >> SHIFT;
    dst[3 * dstStride] = cm[result];

    sum_prev = src2 + src7;
    sum_curr = src3 + src6;
    result = (sum_prev - 5 * sum_curr + src4 * C1 + src5 * C2 + (1 << (SHIFT - 1))) >> SHIFT;
    dst[4 * dstStride] = cm[result];

    sum_prev = src3 + src8;
    sum_curr = src4 + src7;
    result = (sum_prev - 5 * sum_curr + src5 * C1 + src6 * C2 + (1 << (SHIFT - 1))) >> SHIFT;
    dst[5 * dstStride] = cm[result];

    sum_prev = src4 + src9;
    sum_curr = src5 + src8;
    result = (sum_prev - 5 * sum_curr + src6 * C1 + src7 * C2 + (1 << (SHIFT - 1))) >> SHIFT;
    dst[6 * dstStride] = cm[result];

    sum_prev = src5 + src10;
    sum_curr = src6 + src9;
    result = (sum_prev - 5 * sum_curr + src7 * C1 + src8 * C2 + (1 << (SHIFT - 1))) >> SHIFT;
    dst[7 * dstStride] = cm[result];

    dst++;
    src++;
}
}
