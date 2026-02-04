#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  uint8_t *src;
extern int dstStride;
extern int srcStride;
extern  int C1;
extern  int C2;
extern  int w;
extern  uint8_t *cm;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < w; i++) {
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

    int index0 = (-(srcA + src2) + src0 * C1 + src1 * C2 + 8) >> 4;
    int index1 = (-(src0 + src3) + src1 * C1 + src2 * C2 + 8) >> 4;
    int index2 = (-(src1 + src4) + src2 * C1 + src3 * C2 + 8) >> 4;
    int index3 = (-(src2 + src5) + src3 * C1 + src4 * C2 + 8) >> 4;

    if (index0 >= 0 && index1 >= 0 && index2 >= 0 && index3 >= 0) {
        dst[0 * dstStride] = (((dst[0 * dstStride]) + cm[index0] + 1) >> 1);
        dst[1 * dstStride] = (((dst[1 * dstStride]) + cm[index1] + 1) >> 1);
        dst[2 * dstStride] = (((dst[2 * dstStride]) + cm[index2] + 1) >> 1);
        dst[3 * dstStride] = (((dst[3 * dstStride]) + cm[index3] + 1) >> 1);
    }

    int index4 = (-(src3 + src6) + src4 * C1 + src5 * C2 + 8) >> 4;
    int index5 = (-(src4 + src7) + src5 * C1 + src6 * C2 + 8) >> 4;
    int index6 = (-(src5 + src8) + src6 * C1 + src7 * C2 + 8) >> 4;
    int index7 = (-(src6 + src9) + src7 * C1 + src8 * C2 + 8) >> 4;

    if (index4 >= 0 && index5 >= 0 && index6 >= 0 && index7 >= 0) {
        dst[4 * dstStride] = (((dst[4 * dstStride]) + cm[index4] + 1) >> 1);
        dst[5 * dstStride] = (((dst[5 * dstStride]) + cm[index5] + 1) >> 1);
        dst[6 * dstStride] = (((dst[6 * dstStride]) + cm[index6] + 1) >> 1);
        dst[7 * dstStride] = (((dst[7 * dstStride]) + cm[index7] + 1) >> 1);
    }

    dst++;
    src++;
}
}
