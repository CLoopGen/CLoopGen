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
    const int src_1 = src[-srcStride];
    const int src0 = src[0];
    const int src1 = src[srcStride];
    const int src2 = src[2 * srcStride];
    const int src3 = src[3 * srcStride];
    const int src4 = src[4 * srcStride];
    const int src5 = src[5 * srcStride];
    const int src6 = src[6 * srcStride];
    const int src7 = src[7 * srcStride];
    const int src8 = src[8 * srcStride];
    const int src9 = src[9 * srcStride];

    int sum0 = src0 + src1;
    int sum1 = src1 + src2;
    int sum2 = src2 + src3;
    int sum3 = src3 + src4;
    int sum4 = src4 + src5;
    int sum5 = src5 + src6;
    int sum6 = src6 + src7;
    int sum7 = src7 + src8;

    int diff0 = 9 * sum0 - (src_1 + src2);
    int diff1 = 9 * sum1 - (src0 + src3);
    int diff2 = 9 * sum2 - (src1 + src4);
    int diff3 = 9 * sum3 - (src2 + src5);
    int diff4 = 9 * sum4 - (src3 + src6);
    int diff5 = 9 * sum5 - (src4 + src7);
    int diff6 = 9 * sum6 - (src5 + src8);
    int diff7 = 9 * sum7 - (src6 + src9);

    dst[0 * dstStride] = cm[(diff0 + 8) >> 4];
    dst[1 * dstStride] = cm[(diff1 + 8) >> 4];
    dst[2 * dstStride] = cm[(diff2 + 8) >> 4];
    dst[3 * dstStride] = cm[(diff3 + 8) >> 4];
    dst[4 * dstStride] = cm[(diff4 + 8) >> 4];
    dst[5 * dstStride] = cm[(diff5 + 8) >> 4];
    dst[6 * dstStride] = cm[(diff6 + 8) >> 4];
    dst[7 * dstStride] = cm[(diff7 + 8) >> 4];

    src++;
    dst++;
}
}
