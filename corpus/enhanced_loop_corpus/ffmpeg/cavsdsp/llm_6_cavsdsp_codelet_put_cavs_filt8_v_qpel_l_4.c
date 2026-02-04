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

    int temp0 = (-1 * srcB + -2 * srcA + 96 * src0 + 42 * src1 + -7 * src2);
    int temp1 = (-1 * srcA + -2 * src0 + 96 * src1 + 42 * src2 + -7 * src3);
    int temp2 = (-1 * src0 + -2 * src1 + 96 * src2 + 42 * src3 + -7 * src4);
    int temp3 = (-1 * src1 + -2 * src2 + 96 * src3 + 42 * src4 + -7 * src5);
    int temp4 = (-1 * src2 + -2 * src3 + 96 * src4 + 42 * src5 + -7 * src6);
    int temp5 = (-1 * src3 + -2 * src4 + 96 * src5 + 42 * src6 + -7 * src7);
    int temp6 = (-1 * src4 + -2 * src5 + 96 * src6 + 42 * src7 + -7 * src8);
    int temp7 = (-1 * src5 + -2 * src6 + 96 * src7 + 42 * src8 + -7 * src9);

    dst[0 * dstStride] = cm[(temp0 + 64) >> 7];
    dst[1 * dstStride] = cm[(temp1 + 64) >> 7];
    dst[2 * dstStride] = cm[(temp2 + 64) >> 7];
    dst[3 * dstStride] = cm[(temp3 + 64) >> 7];
    dst[4 * dstStride] = cm[(temp4 + 64) >> 7];
    dst[5 * dstStride] = cm[(temp5 + 64) >> 7];
    dst[6 * dstStride] = cm[(temp6 + 64) >> 7];
    dst[7 * dstStride] = cm[(temp7 + 64 + 0 * src10) >> 7];

    dst++;
    src++;
}
}
