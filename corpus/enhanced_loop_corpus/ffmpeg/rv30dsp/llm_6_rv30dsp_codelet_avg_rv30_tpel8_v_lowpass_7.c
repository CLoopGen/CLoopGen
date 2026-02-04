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

    int temp0 = (-(srcA + src2) + src0 * C1 + src1 * C2 + 8) >> 4;
    int temp1 = (-(src0 + src3) + src1 * C1 + src2 * C2 + 8) >> 4;
    int temp2 = (-(src1 + src4) + src2 * C1 + src3 * C2 + 8) >> 4;
    int temp3 = (-(src2 + src5) + src3 * C1 + src4 * C2 + 8) >> 4;
    int temp4 = (-(src3 + src6) + src4 * C1 + src5 * C2 + 8) >> 4;
    int temp5 = (-(src4 + src7) + src5 * C1 + src6 * C2 + 8) >> 4;
    int temp6 = (-(src5 + src8) + src6 * C1 + src7 * C2 + 8) >> 4;
    int temp7 = (-(src6 + src9) + src7 * C1 + src8 * C2 + 8) >> 4;

    uint8_t val0 = cm[temp0];
    uint8_t val1 = cm[temp1];
    uint8_t val2 = cm[temp2];
    uint8_t val3 = cm[temp3];
    uint8_t val4 = cm[temp4];
    uint8_t val5 = cm[temp5];
    uint8_t val6 = cm[temp6];
    uint8_t val7 = cm[temp7];

    dst[0 * dstStride] = (((dst[0 * dstStride]) + val0 + 1) >> 1);
    dst[1 * dstStride] = (((dst[1 * dstStride]) + val1 + 1) >> 1);
    dst[2 * dstStride] = (((dst[2 * dstStride]) + val2 + 1) >> 1);
    dst[3 * dstStride] = (((dst[3 * dstStride]) + val3 + 1) >> 1);
    dst[4 * dstStride] = (((dst[4 * dstStride]) + val4 + 1) >> 1);
    dst[5 * dstStride] = (((dst[5 * dstStride]) + val5 + 1) >> 1);
    dst[6 * dstStride] = (((dst[6 * dstStride]) + val6 + 1) >> 1);
    dst[7 * dstStride] = (((dst[7 * dstStride]) + val7 + 1) >> 1);

    dst++;
    src++;
}
}
