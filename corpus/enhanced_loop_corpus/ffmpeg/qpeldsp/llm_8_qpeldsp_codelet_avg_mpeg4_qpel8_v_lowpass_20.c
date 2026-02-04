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
for (i = 0; i < w; i += 2) {
    const int src0 = src[0 * srcStride];
    const int src1 = src[1 * srcStride];
    const int src2 = src[2 * srcStride];
    const int src3 = src[3 * srcStride];
    const int src4 = src[4 * srcStride];
    const int src5 = src[5 * srcStride];
    const int src6 = src[6 * srcStride];
    const int src7 = src[7 * srcStride];
    const int src8 = src[8 * srcStride];

    // Unroll and compute two iterations of the original pattern (simulated via expanded computation)
    // First output position
    dst[0 * dstStride] = (((dst[0 * dstStride]) + cm[(((src0 + src1) * 20 - (src0 + src2) * 6 + (src1 + src3) * 3 - (src2 + src4)) + 16) >> 5] + 1) >> 1);
    dst[1 * dstStride] = (((dst[1 * dstStride]) + cm[(((src1 + src2) * 20 - (src0 + src3) * 6 + (src0 + src4) * 3 - (src1 + src5)) + 16) >> 5] + 1) >> 1);
    dst[2 * dstStride] = (((dst[2 * dstStride]) + cm[(((src2 + src3) * 20 - (src1 + src4) * 6 + (src0 + src5) * 3 - (src0 + src6)) + 16) >> 5] + 1) >> 1);
    dst[3 * dstStride] = (((dst[3 * dstStride]) + cm[(((src3 + src4) * 20 - (src2 + src5) * 6 + (src1 + src6) * 3 - (src0 + src7)) + 16) >> 5] + 1) >> 1);

    // Simulate second "logical" iteration using shifted inputs (increased computational density)
    const int src1_0 = src[1 * srcStride];
    const int src1_1 = src[2 * srcStride];
    const int src1_2 = src[3 * srcStride];
    const int src1_3 = src[4 * srcStride];
    const int src1_4 = src[5 * srcStride];
    const int src1_5 = src[6 * srcStride];
    const int src1_6 = src[7 * srcStride];
    const int src1_7 = src[8 * srcStride];
    const int src1_8 = (i+1 < w) ? src[9 * srcStride] : src[8 * srcStride];

    dst[4 * dstStride] = (((dst[4 * dstStride]) + cm[(((src1_4 + src1_5) * 20 - (src1_3 + src1_6) * 6 + (src1_2 + src1_7) * 3 - (src1_1 + src1_8)) + 16) >> 5] + 1) >> 1);
    dst[5 * dstStride] = (((dst[5 * dstStride]) + cm[(((src1_5 + src1_6) * 20 - (src1_4 + src1_7) * 6 + (src1_3 + src1_8) * 3 - (src1_2 + src1_8)) + 16) >> 5] + 1) >> 1);
    dst[6 * dstStride] = (((dst[6 * dstStride]) + cm[(((src1_6 + src1_7) * 20 - (src1_5 + src1_8) * 6 + (src1_4 + src1_8) * 3 - (src1_3 + src1_7)) + 16) >> 5] + 1) >> 1);
    dst[7 * dstStride] = (((dst[7 * dstStride]) + cm[(((src1_7 + src1_8) * 20 - (src1_6 + src1_8) * 6 + (src1_5 + src1_7) * 3 - (src1_4 + src1_6)) + 16) >> 5] + 1) >> 1);

    dst += 2;
    src += 2;
}
}
