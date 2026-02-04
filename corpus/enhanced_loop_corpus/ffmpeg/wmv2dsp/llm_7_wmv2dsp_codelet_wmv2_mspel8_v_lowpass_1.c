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
int prev_dst_val = 0;
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

    const int val0 = (9 * (src0 + src1) - (src_1 + src2) + 8) >> 4;
    const int val1 = (9 * (src1 + src2) - (src0 + src3) + 8) >> 4;
    const int val2 = (9 * (src2 + src3) - (src1 + src4) + 8) >> 4;
    const int val3 = (9 * (src3 + src4) - (src2 + src5) + 8) >> 4;
    const int val4 = (9 * (src4 + src5) - (src3 + src6) + 8) >> 4;
    const int val5 = (9 * (src5 + src6) - (src4 + src7) + 8) >> 4;
    const int val6 = (9 * (src6 + src7) - (src5 + src8) + 8) >> 4;
    const int val7 = (9 * (src7 + src8) - (src6 + src9) + 8) >> 4;

    dst[0 * dstStride] = cm[val0 ^ prev_dst_val];
    dst[1 * dstStride] = cm[val1 ^ dst[0 * dstStride]];
    dst[2 * dstStride] = cm[val2 ^ dst[1 * dstStride]];
    dst[3 * dstStride] = cm[val3 ^ dst[2 * dstStride]];
    dst[4 * dstStride] = cm[val4 ^ dst[3 * dstStride]];
    dst[5 * dstStride] = cm[val5 ^ dst[4 * dstStride]];
    dst[6 * dstStride] = cm[val6 ^ dst[5 * dstStride]];
    dst[7 * dstStride] = cm[val7 ^ dst[6 * dstStride]];

    prev_dst_val = dst[7 * dstStride];

    src++;
    dst++;
}
}
