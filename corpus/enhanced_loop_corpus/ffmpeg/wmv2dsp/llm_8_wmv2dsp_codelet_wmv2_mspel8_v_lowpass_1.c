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
for (i = 0; i < w; i += 2) {
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
    const int src10 = src[10 * srcStride];
    const int src11 = src[11 * srcStride];

    dst[0 * dstStride] = cm[(9 * (src0 + src1) - (src_1 + src2) + 8) >> 4];
    dst[1 * dstStride] = cm[(9 * (src1 + src2) - (src0 + src3) + 8) >> 4];
    dst[2 * dstStride] = cm[(9 * (src2 + src3) - (src1 + src4) + 8) >> 4];
    dst[3 * dstStride] = cm[(9 * (src3 + src4) - (src2 + src5) + 8) >> 4];
    dst[4 * dstStride] = cm[(9 * (src4 + src5) - (src3 + src6) + 8) >> 4];
    dst[5 * dstStride] = cm[(9 * (src5 + src6) - (src4 + src7) + 8) >> 4];
    dst[6 * dstStride] = cm[(9 * (src6 + src7) - (src5 + src8) + 8) >> 4];
    dst[7 * dstStride] = cm[(9 * (src7 + src8) - (src6 + src9) + 8) >> 4];

    if (i + 1 < w) {
        const int src_1_next = src[1 - srcStride];
        const int src0_next = src[1];
        const int src1_next = src[1 + srcStride];
        const int src2_next = src[1 + 2 * srcStride];
        const int src3_next = src[1 + 3 * srcStride];
        const int src4_next = src[1 + 4 * srcStride];
        const int src5_next = src[1 + 5 * srcStride];
        const int src6_next = src[1 + 6 * srcStride];
        const int src7_next = src[1 + 7 * srcStride];
        const int src8_next = src[1 + 8 * srcStride];
        const int src9_next = src[1 + 9 * srcStride];

        dst[1 + 0 * dstStride] = cm[(9 * (src0_next + src1_next) - (src_1_next + src2_next) + 8) >> 4];
        dst[1 + 1 * dstStride] = cm[(9 * (src1_next + src2_next) - (src0_next + src3_next) + 8) >> 4];
        dst[1 + 2 * dstStride] = cm[(9 * (src2_next + src3_next) - (src1_next + src4_next) + 8) >> 4];
        dst[1 + 3 * dstStride] = cm[(9 * (src3_next + src4_next) - (src2_next + src5_next) + 8) >> 4];
        dst[1 + 4 * dstStride] = cm[(9 * (src4_next + src5_next) - (src3_next + src6_next) + 8) >> 4];
        dst[1 + 5 * dstStride] = cm[(9 * (src5_next + src6_next) - (src4_next + src7_next) + 8) >> 4];
        dst[1 + 6 * dstStride] = cm[(9 * (src6_next + src7_next) - (src5_next + src8_next) + 8) >> 4];
        dst[1 + 7 * dstStride] = cm[(9 * (src7_next + src8_next) - (src6_next + src9_next) + 8) >> 4];
    }

    src += 2;
    dst += 2;
}
}
