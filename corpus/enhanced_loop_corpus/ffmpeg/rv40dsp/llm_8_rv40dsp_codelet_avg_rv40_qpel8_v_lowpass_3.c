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
for (i = 0; i < w; i += 2) {
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

    // Process two pixels per iteration with reduced memory accesses
    const int val0 = cm[(srcB + src3 - 5 * (srcA + src2) + src0 * C1 + src1 * C2 + (1 << (SHIFT - 1))) >> SHIFT];
    const int val1 = cm[(srcA + src4 - 5 * (src0 + src3) + src1 * C1 + src2 * C2 + (1 << (SHIFT - 1))) >> SHIFT];
    const int val2 = cm[(src0 + src5 - 5 * (src1 + src4) + src2 * C1 + src3 * C2 + (1 << (SHIFT - 1))) >> SHIFT];
    const int val3 = cm[(src1 + src6 - 5 * (src2 + src5) + src3 * C1 + src4 * C2 + (1 << (SHIFT - 1))) >> SHIFT];

    dst[0 * dstStride] = ((dst[0 * dstStride] + val0 + 1) >> 1);
    dst[1 * dstStride] = ((dst[1 * dstStride] + val1 + 1) >> 1);
    dst[2 * dstStride] = ((dst[2 * dstStride] + val2 + 1) >> 1);
    dst[3 * dstStride] = ((dst[3 * dstStride] + val3 + 1) >> 1);

    // Advance pointers by 2 for next pair of operations
    dst += 2;
    src += 2;

    // Handle second pixel group if within bounds
    if (i + 1 < w) {
        const int srcB2 = src[-2 * srcStride];
        const int srcA2 = src[-1 * srcStride];
        const int src0_2 = src[0 * srcStride];
        const int src1_2 = src[1 * srcStride];
        const int src2_2 = src[2 * srcStride];
        const int src3_2 = src[3 * srcStride];
        const int src4_2 = src[4 * srcStride];
        const int src5_2 = src[5 * srcStride];
        const int src6_2 = src[6 * srcStride];
        const int src7_2 = src[7 * srcStride];
        const int src8_2 = src[8 * srcStride];
        const int src9_2 = src[9 * srcStride];
        const int src10_2 = src[10 * srcStride];

        const int val4 = cm[(srcB2 + src3_2 - 5 * (srcA2 + src2_2) + src0_2 * C1 + src1_2 * C2 + (1 << (SHIFT - 1))) >> SHIFT];
        const int val5 = cm[(srcA2 + src4_2 - 5 * (src0_2 + src3_2) + src1_2 * C1 + src2_2 * C2 + (1 << (SHIFT - 1))) >> SHIFT];
        const int val6 = cm[(src0_2 + src5_2 - 5 * (src1_2 + src4_2) + src2_2 * C1 + src3_2 * C2 + (1 << (SHIFT - 1))) >> SHIFT];
        const int val7 = cm[(src1_2 + src6_2 - 5 * (src2_2 + src5_2) + src3_2 * C1 + src4_2 * C2 + (1 << (SHIFT - 1))) >> SHIFT];

        dst[0 * dstStride] = ((dst[0 * dstStride] + val4 + 1) >> 1);
        dst[1 * dstStride] = ((dst[1 * dstStride] + val5 + 1) >> 1);
        dst[2 * dstStride] = ((dst[2 * dstStride] + val6 + 1) >> 1);
        dst[3 * dstStride] = ((dst[3 * dstStride] + val7 + 1) >> 1);

        dst += 2;
        src += 2;
    }
}
}
