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
    const int tmpB0 = tmp[-2 * 8];
    const int tmpA0 = tmp[-1 * 8];
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

    // Process two rows per iteration to increase computational intensity
    // First output row
    dst[0 * dstStride] = ((dst[0 * dstStride]) + cm[((0 * tmpB0 + -1 * tmpA0 + 5 * tmp0 + 5 * tmp1 + -1 * tmp2 + 0 * tmp3 + 64 * src2[0 * srcStride]) + 64) >> 7] + 1) >> 1;
    dst[1 * dstStride] = ((dst[1 * dstStride]) + cm[((0 * tmpA0 + -1 * tmp0 + 5 * tmp1 + 5 * tmp2 + -1 * tmp3 + 0 * tmp4 + 64 * src2[1 * srcStride]) + 64) >> 7] + 1) >> 1;
    dst[2 * dstStride] = ((dst[2 * dstStride]) + cm[((0 * tmp0 + -1 * tmp1 + 5 * tmp2 + 5 * tmp3 + -1 * tmp4 + 0 * tmp5 + 64 * src2[2 * srcStride]) + 64) >> 7] + 1) >> 1;
    dst[3 * dstStride] = ((dst[3 * dstStride]) + cm[((0 * tmp1 + -1 * tmp2 + 5 * tmp3 + 5 * tmp4 + -1 * tmp5 + 0 * tmp6 + 64 * src2[3 * srcStride]) + 64) >> 7] + 1) >> 1;
    dst[4 * dstStride] = ((dst[4 * dstStride]) + cm[((0 * tmp2 + -1 * tmp3 + 5 * tmp4 + 5 * tmp5 + -1 * tmp6 + 0 * tmp7 + 64 * src2[4 * srcStride]) + 64) >> 7] + 1) >> 1;
    dst[5 * dstStride] = ((dst[5 * dstStride]) + cm[((0 * tmp3 + -1 * tmp4 + 5 * tmp5 + 5 * tmp6 + -1 * tmp7 + 0 * tmp8 + 64 * src2[5 * srcStride]) + 64) >> 7] + 1) >> 1;
    dst[6 * dstStride] = ((dst[6 * dstStride]) + cm[((0 * tmp4 + -1 * tmp5 + 5 * tmp6 + 5 * tmp7 + -1 * tmp8 + 0 * tmp9 + 64 * src2[6 * srcStride]) + 64) >> 7] + 1) >> 1;
    dst[7 * dstStride] = ((dst[7 * dstStride]) + cm[((0 * tmp5 + -1 * tmp6 + 5 * tmp7 + 5 * tmp8 + -1 * tmp9 + 0 * tmp10 + 64 * src2[7 * srcStride]) + 64) >> 7] + 1) >> 1;

    // Second output row using offset data if available (unrolled with bounds-aware logic)
    if (i + 1 < w) {
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

        uint8_t *dst_offset = dst + dstStride;
        uint8_t *src2_offset = src2 + srcStride;

        dst_offset[0 * dstStride] = ((dst_offset[0 * dstStride]) + cm[((0 * tmpB1 + -1 * tmpA1 + 5 * tmp0_1 + 5 * tmp1_1 + -1 * tmp2_1 + 0 * tmp3_1 + 64 * src2_offset[0 * srcStride]) + 64) >> 7] + 1) >> 1;
        dst_offset[1 * dstStride] = ((dst_offset[1 * dstStride]) + cm[((0 * tmpA1 + -1 * tmp0_1 + 5 * tmp1_1 + 5 * tmp2_1 + -1 * tmp3_1 + 0 * tmp4_1 + 64 * src2_offset[1 * srcStride]) + 64) >> 7] + 1) >> 1;
        dst_offset[2 * dstStride] = ((dst_offset[2 * dstStride]) + cm[((0 * tmp0_1 + -1 * tmp1_1 + 5 * tmp2_1 + 5 * tmp3_1 + -1 * tmp4_1 + 0 * tmp5_1 + 64 * src2_offset[2 * srcStride]) + 64) >> 7] + 1) >> 1;
        dst_offset[3 * dstStride] = ((dst_offset[3 * dstStride]) + cm[((0 * tmp1_1 + -1 * tmp2_1 + 5 * tmp3_1 + 5 * tmp4_1 + -1 * tmp5_1 + 0 * tmp6_1 + 64 * src2_offset[3 * srcStride]) + 64) >> 7] + 1) >> 1;
        dst_offset[4 * dstStride] = ((dst_offset[4 * dstStride]) + cm[((0 * tmp2_1 + -1 * tmp3_1 + 5 * tmp4_1 + 5 * tmp5_1 + -1 * tmp6_1 + 0 * tmp7_1 + 64 * src2_offset[4 * srcStride]) + 64) >> 7] + 1) >> 1;
        dst_offset[5 * dstStride] = ((dst_offset[5 * dstStride]) + cm[((0 * tmp3_1 + -1 * tmp4_1 + 5 * tmp5_1 + 5 * tmp6_1 + -1 * tmp7_1 + 0 * tmp8_1 + 64 * src2_offset[5 * srcStride]) + 64) >> 7] + 1) >> 1;
        dst_offset[6 * dstStride] = ((dst_offset[6 * dstStride]) + cm[((0 * tmp4_1 + -1 * tmp5_1 + 5 * tmp6_1 + 5 * tmp7_1 + -1 * tmp8_1 + 0 * tmp9_1 + 64 * src2_offset[6 * srcStride]) + 64) >> 7] + 1) >> 1;
        dst_offset[7 * dstStride] = ((dst_offset[7 * dstStride]) + cm[((0 * tmp5_1 + -1 * tmp6_1 + 5 * tmp7_1 + 5 * tmp8_1 + -1 * tmp9_1 + 0 * tmp10_1 + 64 * src2_offset[7 * srcStride]) + 64) >> 7] + 1) >> 1;
    }

    dst += 2;
    tmp += 2;
    src2 += 2;
}
}
