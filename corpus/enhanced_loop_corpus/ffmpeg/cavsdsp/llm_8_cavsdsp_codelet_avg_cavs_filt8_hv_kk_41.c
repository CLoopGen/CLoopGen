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

    // Process two rows per iteration to increase computational intensity
    if (i + 0 < w) {
        dst[0 * dstStride] = ((dst[0 * dstStride]) + cm[((0 * tmpB + -1 * tmpA + 5 * tmp0 + 5 * tmp1 + -1 * tmp2 + 0 * tmp3 + 64 * src2[0 * srcStride]) + 512) >> 10] + 1) >> 1;
        dst[1 * dstStride] = ((dst[1 * dstStride]) + cm[((0 * tmpA + -1 * tmp0 + 5 * tmp1 + 5 * tmp2 + -1 * tmp3 + 0 * tmp4 + 64 * src2[1 * srcStride]) + 512) >> 10] + 1) >> 1;
        dst[2 * dstStride] = ((dst[2 * dstStride]) + cm[((0 * tmp0 + -1 * tmp1 + 5 * tmp2 + 5 * tmp3 + -1 * tmp4 + 0 * tmp5 + 64 * src2[2 * srcStride]) + 512) >> 10] + 1) >> 1;
        dst[3 * dstStride] = ((dst[3 * dstStride]) + cm[((0 * tmp1 + -1 * tmp2 + 5 * tmp3 + 5 * tmp4 + -1 * tmp5 + 0 * tmp6 + 64 * src2[3 * srcStride]) + 512) >> 10] + 1) >> 1;
        dst[4 * dstStride] = ((dst[4 * dstStride]) + cm[((0 * tmp2 + -1 * tmp3 + 5 * tmp4 + 5 * tmp5 + -1 * tmp6 + 0 * tmp7 + 64 * src2[4 * srcStride]) + 512) >> 10] + 1) >> 1;
        dst[5 * dstStride] = ((dst[5 * dstStride]) + cm[((0 * tmp3 + -1 * tmp4 + 5 * tmp5 + 5 * tmp6 + -1 * tmp7 + 0 * tmp8 + 64 * src2[5 * srcStride]) + 512) >> 10] + 1) >> 1;
        dst[6 * dstStride] = ((dst[6 * dstStride]) + cm[((0 * tmp4 + -1 * tmp5 + 5 * tmp6 + 5 * tmp7 + -1 * tmp8 + 0 * tmp9 + 64 * src2[6 * srcStride]) + 512) >> 10] + 1) >> 1;
        dst[7 * dstStride] = ((dst[7 * dstStride]) + cm[((0 * tmp5 + -1 * tmp6 + 5 * tmp7 + 5 * tmp8 + -1 * tmp9 + 0 * tmp10 + 64 * src2[7 * srcStride]) + 512) >> 10] + 1) >> 1;
    }

    if (i + 1 < w) {
        const int tmpB2 = tmp[-1 * 8];
        const int tmpA2 = tmp[0 * 8];
        const int tmp02 = tmp[1 * 8];
        const int tmp12 = tmp[2 * 8];
        const int tmp22 = tmp[3 * 8];
        const int tmp32 = tmp[4 * 8];
        const int tmp42 = tmp[5 * 8];
        const int tmp52 = tmp[6 * 8];
        const int tmp62 = tmp[7 * 8];
        const int tmp72 = tmp[8 * 8];
        const int tmp82 = tmp[9 * 8];
        const int tmp92 = tmp[10 * 8];
        const int tmp102 = tmp[11 * 8];

        uint8_t* dst2 = dst + 1;
        int16_t* tmp_ptr2 = tmp + 1;
        uint8_t* src2_ptr2 = src2 + 1;

        dst2[0 * dstStride] = ((dst2[0 * dstStride]) + cm[((0 * tmpB2 + -1 * tmpA2 + 5 * tmp02 + 5 * tmp12 + -1 * tmp22 + 0 * tmp32 + 64 * src2_ptr2[0 * srcStride]) + 512) >> 10] + 1) >> 1;
        dst2[1 * dstStride] = ((dst2[1 * dstStride]) + cm[((0 * tmpA2 + -1 * tmp02 + 5 * tmp12 + 5 * tmp22 + -1 * tmp32 + 0 * tmp42 + 64 * src2_ptr2[1 * srcStride]) + 512) >> 10] + 1) >> 1;
        dst2[2 * dstStride] = ((dst2[2 * dstStride]) + cm[((0 * tmp02 + -1 * tmp12 + 5 * tmp22 + 5 * tmp32 + -1 * tmp42 + 0 * tmp52 + 64 * src2_ptr2[2 * srcStride]) + 512) >> 10] + 1) >> 1;
        dst2[3 * dstStride] = ((dst2[3 * dstStride]) + cm[((0 * tmp12 + -1 * tmp22 + 5 * tmp32 + 5 * tmp42 + -1 * tmp52 + 0 * tmp62 + 64 * src2_ptr2[3 * srcStride]) + 512) >> 10] + 1) >> 1;
        dst2[4 * dstStride] = ((dst2[4 * dstStride]) + cm[((0 * tmp22 + -1 * tmp32 + 5 * tmp42 + 5 * tmp52 + -1 * tmp62 + 0 * tmp72 + 64 * src2_ptr2[4 * srcStride]) + 512) >> 10] + 1) >> 1;
        dst2[5 * dstStride] = ((dst2[5 * dstStride]) + cm[((0 * tmp32 + -1 * tmp42 + 5 * tmp52 + 5 * tmp62 + -1 * tmp72 + 0 * tmp82 + 64 * src2_ptr2[5 * srcStride]) + 512) >> 10] + 1) >> 1;
        dst2[6 * dstStride] = ((dst2[6 * dstStride]) + cm[((0 * tmp42 + -1 * tmp52 + 5 * tmp62 + 5 * tmp72 + -1 * tmp82 + 0 * tmp92 + 64 * src2_ptr2[6 * srcStride]) + 512) >> 10] + 1) >> 1;
        dst2[7 * dstStride] = ((dst2[7 * dstStride]) + cm[((0 * tmp52 + -1 * tmp62 + 5 * tmp72 + 5 * tmp82 + -1 * tmp92 + 0 * tmp102 + 64 * src2_ptr2[7 * srcStride]) + 512) >> 10] + 1) >> 1;
    }

    dst += 2;
    tmp += 2;
    src2 += 2;
}
}
