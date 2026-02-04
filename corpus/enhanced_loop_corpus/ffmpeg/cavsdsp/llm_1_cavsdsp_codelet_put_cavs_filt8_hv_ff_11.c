#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  uint8_t *src2;
extern ptrdiff_t dstStride;
extern ptrdiff_t srcStride;
extern int16_t *tmp;
extern  int w;
extern  uint8_t *cm;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < w; i += 2) {
        if (i + 1 < w) {
            // Unroll two iterations of the original loop
            const int tmpB0 = tmp[-2 * 8];
            const int tmpA0 = tmp[-1 * 8];
            const int tmp0_0 = tmp[0 * 8];
            const int tmp1_0 = tmp[1 * 8];
            const int tmp2_0 = tmp[2 * 8];
            const int tmp3_0 = tmp[3 * 8];
            const int tmp4_0 = tmp[4 * 8];
            const int tmp5_0 = tmp[5 * 8];
            const int tmp6_0 = tmp[6 * 8];
            const int tmp7_0 = tmp[7 * 8];
            const int tmp8_0 = tmp[8 * 8];
            const int tmp9_0 = tmp[9 * 8];
            const int tmp10_0 = tmp[10 * 8];

            dst[0 * dstStride] = cm[((-1 * tmpB0 + -2 * tmpA0 + 96 * tmp0_0 + 42 * tmp1_0 + -7 * tmp2_0 + 0 * tmp3_0 + 64 * src2[0 * srcStride]) + 512) >> 10];
            dst[1 * dstStride] = cm[((-1 * tmpA0 + -2 * tmp0_0 + 96 * tmp1_0 + 42 * tmp2_0 + -7 * tmp3_0 + 0 * tmp4_0 + 64 * src2[1 * srcStride]) + 512) >> 10];
            dst[2 * dstStride] = cm[((-1 * tmp0_0 + -2 * tmp1_0 + 96 * tmp2_0 + 42 * tmp3_0 + -7 * tmp4_0 + 0 * tmp5_0 + 64 * src2[2 * srcStride]) + 512) >> 10];
            dst[3 * dstStride] = cm[((-1 * tmp1_0 + -2 * tmp2_0 + 96 * tmp3_0 + 42 * tmp4_0 + -7 * tmp5_0 + 0 * tmp6_0 + 64 * src2[3 * srcStride]) + 512) >> 10];
            dst[4 * dstStride] = cm[((-1 * tmp2_0 + -2 * tmp3_0 + 96 * tmp4_0 + 42 * tmp5_0 + -7 * tmp6_0 + 0 * tmp7_0 + 64 * src2[4 * srcStride]) + 512) >> 10];
            dst[5 * dstStride] = cm[((-1 * tmp3_0 + -2 * tmp4_0 + 96 * tmp5_0 + 42 * tmp6_0 + -7 * tmp7_0 + 0 * tmp8_0 + 64 * src2[5 * srcStride]) + 512) >> 10];
            dst[6 * dstStride] = cm[((-1 * tmp4_0 + -2 * tmp5_0 + 96 * tmp6_0 + 42 * tmp7_0 + -7 * tmp8_0 + 0 * tmp9_0 + 64 * src2[6 * srcStride]) + 512) >> 10];
            dst[7 * dstStride] = cm[((-1 * tmp5_0 + -2 * tmp6_0 + 96 * tmp7_0 + 42 * tmp8_0 + -7 * tmp9_0 + 0 * tmp10_0 + 64 * src2[7 * srcStride]) + 512) >> 10];

            // Second unrolled iteration
            const int tmpB1 = tmp[-1 * 8];
            const int tmpA1 = tmp[0 * 8];
            const int tmp0_1 = tmp[1 * 8];
            const int tmp1_1 = tmp[2 * 8];
            const int tmp2_1 = tmp[3 * 8];
            const int tmp3_1 = tmp[4 * 8];
            const int tmp4_1 = tmp[5 * 8];
            const int tmp5_1 = tmp[6 * 8];
            const int tmp6_1 = tmp[7 * 8];
            const int tmp7_1 = tmp[8 * 8];
            const int tmp8_1 = tmp[9 * 8];
            const int tmp9_1 = tmp[10 * 8];
            const int tmp10_1 = tmp[11 * 8];

            uint8_t *dst1 = dst + dstStride * 8;
            uint8_t *src2_1 = src2 + srcStride * 8;

            dst1[0 * dstStride] = cm[((-1 * tmpB1 + -2 * tmpA1 + 96 * tmp0_1 + 42 * tmp1_1 + -7 * tmp2_1 + 0 * tmp3_1 + 64 * src2_1[0 * srcStride]) + 512) >> 10];
            dst1[1 * dstStride] = cm[((-1 * tmpA1 + -2 * tmp0_1 + 96 * tmp1_1 + 42 * tmp2_1 + -7 * tmp3_1 + 0 * tmp4_1 + 64 * src2_1[1 * srcStride]) + 512) >> 10];
            dst1[2 * dstStride] = cm[((-1 * tmp0_1 + -2 * tmp1_1 + 96 * tmp2_1 + 42 * tmp3_1 + -7 * tmp4_1 + 0 * tmp5_1 + 64 * src2_1[2 * srcStride]) + 512) >> 10];
            dst1[3 * dstStride] = cm[((-1 * tmp1_1 + -2 * tmp2_1 + 96 * tmp3_1 + 42 * tmp4_1 + -7 * tmp5_1 + 0 * tmp6_1 + 64 * src2_1[3 * srcStride]) + 512) >> 10];
            dst1[4 * dstStride] = cm[((-1 * tmp2_1 + -2 * tmp3_1 + 96 * tmp4_1 + 42 * tmp5_1 + -7 * tmp6_1 + 0 * tmp7_1 + 64 * src2_1[4 * srcStride]) + 512) >> 10];
            dst1[5 * dstStride] = cm[((-1 * tmp3_1 + -2 * tmp4_1 + 96 * tmp5_1 + 42 * tmp6_1 + -7 * tmp7_1 + 0 * tmp8_1 + 64 * src2_1[5 * srcStride]) + 512) >> 10];
            dst1[6 * dstStride] = cm[((-1 * tmp4_1 + -2 * tmp5_1 + 96 * tmp6_1 + 42 * tmp7_1 + -7 * tmp8_1 + 0 * tmp9_1 + 64 * src2_1[6 * srcStride]) + 512) >> 10];
            dst1[7 * dstStride] = cm[((-1 * tmp5_1 + -2 * tmp6_1 + 96 * tmp7_1 + 42 * tmp8_1 + -7 * tmp9_1 + 0 * tmp10_1 + 64 * src2_1[7 * srcStride]) + 512) >> 10];

            tmp += 2;
            dst += 2;
            src2 += 2;
        } else {
            // Handle remaining single iteration
            const int tmpB = tmp[-2 * 8];
            const int tmpA = tmp[-1 * 8];
            const int tmp0 = tmp[0 * 8];
            const int tmp1 = tmp[1 * 8];
            const int tmp2 = tmp[2 * 8];
            const int tmp3 = tmp[3 * 8];
            const int tmp4 = tmp[4 * 8];
            const int tmp5 = tmp[5 * 8];
            const int tmp6 = tmp[6 * 8];
            const int tmp7 = tmp[7 * 8];
            const int tmp8 = tmp[8 * 8];
            const int tmp9 = tmp[9 * 8];
            const int tmp10 = tmp[10 * 8];

            dst[0 * dstStride] = cm[((-1 * tmpB + -2 * tmpA + 96 * tmp0 + 42 * tmp1 + -7 * tmp2 + 0 * tmp3 + 64 * src2[0 * srcStride]) + 512) >> 10];
            dst[1 * dstStride] = cm[((-1 * tmpA + -2 * tmp0 + 96 * tmp1 + 42 * tmp2 + -7 * tmp3 + 0 * tmp4 + 64 * src2[1 * srcStride]) + 512) >> 10];
            dst[2 * dstStride] = cm[((-1 * tmp0 + -2 * tmp1 + 96 * tmp2 + 42 * tmp3 + -7 * tmp4 + 0 * tmp5 + 64 * src2[2 * srcStride]) + 512) >> 10];
            dst[3 * dstStride] = cm[((-1 * tmp1 + -2 * tmp2 + 96 * tmp3 + 42 * tmp4 + -7 * tmp5 + 0 * tmp6 + 64 * src2[3 * srcStride]) + 512) >> 10];
            dst[4 * dstStride] = cm[((-1 * tmp2 + -2 * tmp3 + 96 * tmp4 + 42 * tmp5 + -7 * tmp6 + 0 * tmp7 + 64 * src2[4 * srcStride]) + 512) >> 10];
            dst[5 * dstStride] = cm[((-1 * tmp3 + -2 * tmp4 + 96 * tmp5 + 42 * tmp6 + -7 * tmp7 + 0 * tmp8 + 64 * src2[5 * srcStride]) + 512) >> 10];
            dst[6 * dstStride] = cm[((-1 * tmp4 + -2 * tmp5 + 96 * tmp6 + 42 * tmp7 + -7 * tmp8 + 0 * tmp9 + 64 * src2[6 * srcStride]) + 512) >> 10];
            dst[7 * dstStride] = cm[((-1 * tmp5 + -2 * tmp6 + 96 * tmp7 + 42 * tmp8 + -7 * tmp9 + 0 * tmp10 + 64 * src2[7 * srcStride]) + 512) >> 10];

            dst++;
            tmp++;
            src2++;
        }
    }
}
