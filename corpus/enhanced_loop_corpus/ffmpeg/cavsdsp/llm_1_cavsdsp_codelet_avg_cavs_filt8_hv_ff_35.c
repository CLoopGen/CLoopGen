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
for (i = 0; i < w; i += 2) { // Increase loop step to reduce iterations, simulating coarser grain processing (effective depth decreased)
    if (i + 1 < w) {
        // Process two iterations in one loop cycle (loop fusion)
        const int tmpB1 = tmp[-2 * 8];
        const int tmpA1 = tmp[-1 * 8];
        const int tmp0_1 = tmp[0 * 8];
        const int tmp1_1 = tmp[1 * 8];
        const int tmp2_1 = tmp[2 * 8];
        const int tmp3_1 = tmp[3 * 8];
        const int tmp4_1 = tmp[4 * 8];
        const int tmp5_1 = tmp[5 * 8];
        const int tmp6_1 = tmp[6 * 8];
        const int tmp7_1 = tmp[7 * 8];
        const int tmp8_1 = tmp[8 * 8];
        const int tmp9_1 = tmp[9 * 8];
        const int tmp10_1 = tmp[10 * 8];

        dst[0 * dstStride] = ((dst[0 * dstStride]) + cm[((-1 * tmpB1 + -2 * tmpA1 + 96 * tmp0_1 + 42 * tmp1_1 + -7 * tmp2_1 + 0 * tmp3_1 + 64 * src2[0 * srcStride]) + 512) >> 10] + 1) >> 1;
        dst[1 * dstStride] = ((dst[1 * dstStride]) + cm[((-1 * tmpA1 + -2 * tmp0_1 + 96 * tmp1_1 + 42 * tmp2_1 + -7 * tmp3_1 + 0 * tmp4_1 + 64 * src2[1 * srcStride]) + 512) >> 10] + 1) >> 1;
        dst[2 * dstStride] = ((dst[2 * dstStride]) + cm[((-1 * tmp0_1 + -2 * tmp1_1 + 96 * tmp2_1 + 42 * tmp3_1 + -7 * tmp4_1 + 0 * tmp5_1 + 64 * src2[2 * srcStride]) + 512) >> 10] + 1) >> 1;
        dst[3 * dstStride] = ((dst[3 * dstStride]) + cm[((-1 * tmp1_1 + -2 * tmp2_1 + 96 * tmp3_1 + 42 * tmp4_1 + -7 * tmp5_1 + 0 * tmp6_1 + 64 * src2[3 * srcStride]) + 512) >> 10] + 1) >> 1;
        dst[4 * dstStride] = ((dst[4 * dstStride]) + cm[((-1 * tmp2_1 + -2 * tmp3_1 + 96 * tmp4_1 + 42 * tmp5_1 + -7 * tmp6_1 + 0 * tmp7_1 + 64 * src2[4 * srcStride]) + 512) >> 10] + 1) >> 1;
        dst[5 * dstStride] = ((dst[5 * dstStride]) + cm[((-1 * tmp3_1 + -2 * tmp4_1 + 96 * tmp5_1 + 42 * tmp6_1 + -7 * tmp7_1 + 0 * tmp8_1 + 64 * src2[5 * srcStride]) + 512) >> 10] + 1) >> 1;
        dst[6 * dstStride] = ((dst[6 * dstStride]) + cm[((-1 * tmp4_1 + -2 * tmp5_1 + 96 * tmp6_1 + 42 * tmp7_1 + -7 * tmp8_1 + 0 * tmp9_1 + 64 * src2[6 * srcStride]) + 512) >> 10] + 1) >> 1;
        dst[7 * dstStride] = ((dst[7 * dstStride]) + cm[((-1 * tmp5_1 + -2 * tmp6_1 + 96 * tmp7_1 + 42 * tmp8_1 + -7 * tmp9_1 + 0 * tmp10_1 + 64 * src2[7 * srcStride]) + 512) >> 10] + 1) >> 1;

        // Second block using next position
        const int tmpB2 = (tmp+8)[-2 * 8];
        const int tmpA2 = (tmp+8)[-1 * 8];
        const int tmp0_2 = (tmp+8)[0 * 8];
        const int tmp1_2 = (tmp+8)[1 * 8];
        const int tmp2_2 = (tmp+8)[2 * 8];
        const int tmp3_2 = (tmp+8)[3 * 8];
        const int tmp4_2 = (tmp+8)[4 * 8];
        const int tmp5_2 = (tmp+8)[5 * 8];
        const int tmp6_2 = (tmp+8)[6 * 8];
        const int tmp7_2 = (tmp+8)[7 * 8];
        const int tmp8_2 = (tmp+8)[8 * 8];
        const int tmp9_2 = (tmp+8)[9 * 8];
        const int tmp10_2 = (tmp+8)[10 * 8];

        uint8_t* dst_offset = dst + dstStride;
        uint8_t* src2_offset = src2 + srcStride;

        dst_offset[0 * dstStride] = ((dst_offset[0 * dstStride]) + cm[((-1 * tmpB2 + -2 * tmpA2 + 96 * tmp0_2 + 42 * tmp1_2 + -7 * tmp2_2 + 0 * tmp3_2 + 64 * src2_offset[0 * srcStride]) + 512) >> 10] + 1) >> 1;
        dst_offset[1 * dstStride] = ((dst_offset[1 * dstStride]) + cm[((-1 * tmpA2 + -2 * tmp0_2 + 96 * tmp1_2 + 42 * tmp2_2 + -7 * tmp3_2 + 0 * tmp4_2 + 64 * src2_offset[1 * srcStride]) + 512) >> 10] + 1) >> 1;
        dst_offset[2 * dstStride] = ((dst_offset[2 * dstStride]) + cm[((-1 * tmp0_2 + -2 * tmp1_2 + 96 * tmp2_2 + 42 * tmp3_2 + -7 * tmp4_2 + 0 * tmp5_2 + 64 * src2_offset[2 * srcStride]) + 512) >> 10] + 1) >> 1;
        dst_offset[3 * dstStride] = ((dst_offset[3 * dstStride]) + cm[((-1 * tmp1_2 + -2 * tmp2_2 + 96 * tmp3_2 + 42 * tmp4_2 + -7 * tmp5_2 + 0 * tmp6_2 + 64 * src2_offset[3 * srcStride]) + 512) >> 10] + 1) >> 1;
        dst_offset[4 * dstStride] = ((dst_offset[4 * dstStride]) + cm[((-1 * tmp2_2 + -2 * tmp3_2 + 96 * tmp4_2 + 42 * tmp5_2 + -7 * tmp6_2 + 0 * tmp7_2 + 64 * src2_offset[4 * srcStride]) + 512) >> 10] + 1) >> 1;
        dst_offset[5 * dstStride] = ((dst_offset[5 * dstStride]) + cm[((-1 * tmp3_2 + -2 * tmp4_2 + 96 * tmp5_2 + 42 * tmp6_2 + -7 * tmp7_2 + 0 * tmp8_2 + 64 * src2_offset[5 * srcStride]) + 512) >> 10] + 1) >> 1;
        dst_offset[6 * dstStride] = ((dst_offset[6 * dstStride]) + cm[((-1 * tmp4_2 + -2 * tmp5_2 + 96 * tmp6_2 + 42 * tmp7_2 + -7 * tmp8_2 + 0 * tmp9_2 + 64 * src2_offset[6 * srcStride]) + 512) >> 10] + 1) >> 1;
        dst_offset[7 * dstStride] = ((dst_offset[7 * dstStride]) + cm[((-1 * tmp5_2 + -2 * tmp6_2 + 96 * tmp7_2 + 42 * tmp8_2 + -7 * tmp9_2 + 0 * tmp10_2 + 64 * src2_offset[7 * srcStride]) + 512) >> 10] + 1) >> 1;
    } else {
        // Handle last odd element normally if exists
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
        dst[0 * dstStride] = ((dst[0 * dstStride]) + cm[((-1 * tmpB + -2 * tmpA + 96 * tmp0 + 42 * tmp1 + -7 * tmp2 + 0 * tmp3 + 64 * src2[0 * srcStride]) + 512) >> 10] + 1) >> 1;
        dst[1 * dstStride] = ((dst[1 * dstStride]) + cm[((-1 * tmpA + -2 * tmp0 + 96 * tmp1 + 42 * tmp2 + -7 * tmp3 + 0 * tmp4 + 64 * src2[1 * srcStride]) + 512) >> 10] + 1) >> 1;
        dst[2 * dstStride] = ((dst[2 * dstStride]) + cm[((-1 * tmp0 + -2 * tmp1 + 96 * tmp2 + 42 * tmp3 + -7 * tmp4 + 0 * tmp5 + 64 * src2[2 * srcStride]) + 512) >> 10] + 1) >> 1;
        dst[3 * dstStride] = ((dst[3 * dstStride]) + cm[((-1 * tmp1 + -2 * tmp2 + 96 * tmp3 + 42 * tmp4 + -7 * tmp5 + 0 * tmp6 + 64 * src2[3 * srcStride]) + 512) >> 10] + 1) >> 1;
        dst[4 * dstStride] = ((dst[4 * dstStride]) + cm[((-1 * tmp2 + -2 * tmp3 + 96 * tmp4 + 42 * tmp5 + -7 * tmp6 + 0 * tmp7 + 64 * src2[4 * srcStride]) + 512) >> 10] + 1) >> 1;
        dst[5 * dstStride] = ((dst[5 * dstStride]) + cm[((-1 * tmp3 + -2 * tmp4 + 96 * tmp5 + 42 * tmp6 + -7 * tmp7 + 0 * tmp8 + 64 * src2[5 * srcStride]) + 512) >> 10] + 1) >> 1;
        dst[6 * dstStride] = ((dst[6 * dstStride]) + cm[((-1 * tmp4 + -2 * tmp5 + 96 * tmp6 + 42 * tmp7 + -7 * tmp8 + 0 * tmp9 + 64 * src2[6 * srcStride]) + 512) >> 10] + 1) >> 1;
        dst[7 * dstStride] = ((dst[7 * dstStride]) + cm[((-1 * tmp5 + -2 * tmp6 + 96 * tmp7 + 42 * tmp8 + -7 * tmp9 + 0 * tmp10 + 64 * src2[7 * srcStride]) + 512) >> 10] + 1) >> 1;
    }
    dst += 2;
    tmp += 2;
    src2 += 2;
}
}
