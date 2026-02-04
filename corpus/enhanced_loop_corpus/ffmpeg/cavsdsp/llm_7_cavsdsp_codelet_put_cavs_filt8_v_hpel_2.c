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
for (i = 0; i < w; i += 8) {
    if (i + 7 >= w) break;

    const int srcB0 = src[-2 * srcStride];
    const int srcA0 = src[-1 * srcStride];
    const int src0_0 = src[0 * srcStride];
    const int src1_0 = src[1 * srcStride];
    const int src2_0 = src[2 * srcStride];
    const int src3_0 = src[3 * srcStride];
    const int src4_0 = src[4 * srcStride];
    const int src5_0 = src[5 * srcStride];
    const int src6_0 = src[6 * srcStride];
    const int src7_0 = src[7 * srcStride];
    const int src8_0 = src[8 * srcStride];
    const int src9_0 = src[9 * srcStride];
    const int src10_0 = src[10 * srcStride];

    dst[0 * dstStride] = cm[((0 * srcB0 + -1 * srcA0 + 5 * src0_0 + 5 * src1_0 + -1 * src2_0 + 0 * src3_0) + 4) >> 3];
    dst[1 * dstStride] = cm[((0 * srcA0 + -1 * src0_0 + 5 * src1_0 + 5 * src2_0 + -1 * src3_0 + 0 * src4_0) + 4) >> 3];
    dst[2 * dstStride] = cm[((0 * src0_0 + -1 * src1_0 + 5 * src2_0 + 5 * src3_0 + -1 * src4_0 + 0 * src5_0) + 4) >> 3];
    dst[3 * dstStride] = cm[((0 * src1_0 + -1 * src2_0 + 5 * src3_0 + 5 * src4_0 + -1 * src5_0 + 0 * src6_0) + 4) >> 3];
    dst[4 * dstStride] = cm[((0 * src2_0 + -1 * src3_0 + 5 * src4_0 + 5 * src5_0 + -1 * src6_0 + 0 * src7_0) + 4) >> 3];
    dst[5 * dstStride] = cm[((0 * src3_0 + -1 * src4_0 + 5 * src5_0 + 5 * src6_0 + -1 * src7_0 + 0 * src8_0) + 4) >> 3];
    dst[6 * dstStride] = cm[((0 * src4_0 + -1 * src5_0 + 5 * src6_0 + 5 * src7_0 + -1 * src8_0 + 0 * src9_0) + 4) >> 3];
    dst[7 * dstStride] = cm[((0 * src5_0 + -1 * src6_0 + 5 * src7_0 + 5 * src8_0 + -1 * src9_0 + 0 * src10_0) + 4) >> 3];

    for (int j = 0; j < 8; j++) {
        dst++;
        src++;
    }
}
}
