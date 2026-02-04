#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern ptrdiff_t dstStride;
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
    const int tmp11 = tmp[11 * 8];
    const int tmp12 = tmp[12 * 8];

    // First output pixel
    dst[0 * dstStride] = ((dst[0 * dstStride]) + cm[((0 * tmpB0 + -7 * tmpA0 + 42 * tmp0 + 96 * tmp1 + -2 * tmp2 + -1 * tmp3) + 512) >> 10] + 1) >> 1;
    dst[1 * dstStride] = ((dst[1 * dstStride]) + cm[((0 * tmpA0 + -7 * tmp0 + 42 * tmp1 + 96 * tmp2 + -2 * tmp3 + -1 * tmp4) + 512) >> 10] + 1) >> 1;
    dst[2 * dstStride] = ((dst[2 * dstStride]) + cm[((0 * tmp0 + -7 * tmp1 + 42 * tmp2 + 96 * tmp3 + -2 * tmp4 + -1 * tmp5) + 512) >> 10] + 1) >> 1;
    dst[3 * dstStride] = ((dst[3 * dstStride]) + cm[((0 * tmp1 + -7 * tmp2 + 42 * tmp3 + 96 * tmp4 + -2 * tmp5 + -1 * tmp6) + 512) >> 10] + 1) >> 1;
    dst[4 * dstStride] = ((dst[4 * dstStride]) + cm[((0 * tmp2 + -7 * tmp3 + 42 * tmp4 + 96 * tmp5 + -2 * tmp6 + -1 * tmp7) + 512) >> 10] + 1) >> 1;
    dst[5 * dstStride] = ((dst[5 * dstStride]) + cm[((0 * tmp3 + -7 * tmp4 + 42 * tmp5 + 96 * tmp6 + -2 * tmp7 + -1 * tmp8) + 512) >> 10] + 1) >> 1;
    dst[6 * dstStride] = ((dst[6 * dstStride]) + cm[((0 * tmp4 + -7 * tmp5 + 42 * tmp6 + 96 * tmp7 + -2 * tmp8 + -1 * tmp9) + 512) >> 10] + 1) >> 1;
    dst[7 * dstStride] = ((dst[7 * dstStride]) + cm[((0 * tmp5 + -7 * tmp6 + 42 * tmp7 + 96 * tmp8 + -2 * tmp9 + -1 * tmp10) + 512) >> 10] + 1) >> 1;

    // Second output pixel group (shifted by one sample)
    if (i + 1 < w) {
        const int tmpB1 = tmpA0;
        const int tmpA1 = tmp0;
        const int tmp1_0 = tmp1;
        const int tmp1_1 = tmp2;
        const int tmp1_2 = tmp3;
        const int tmp1_3 = tmp4;
        const int tmp1_4 = tmp5;
        const int tmp1_5 = tmp6;
        const int tmp1_6 = tmp7;
        const int tmp1_7 = tmp8;
        const int tmp1_8 = tmp9;
        const int tmp1_9 = tmp10;
        const int tmp1_10 = tmp11;
        const int tmp1_11 = tmp12;

        uint8_t* dst1 = dst + dstStride;
        dst1[0 * dstStride] = ((dst1[0 * dstStride]) + cm[((0 * tmpB1 + -7 * tmpA1 + 42 * tmp1_0 + 96 * tmp1_1 + -2 * tmp1_2 + -1 * tmp1_3) + 512) >> 10] + 1) >> 1;
        dst1[1 * dstStride] = ((dst1[1 * dstStride]) + cm[((0 * tmpA1 + -7 * tmp1_0 + 42 * tmp1_1 + 96 * tmp1_2 + -2 * tmp1_3 + -1 * tmp1_4) + 512) >> 10] + 1) >> 1;
        dst1[2 * dstStride] = ((dst1[2 * dstStride]) + cm[((0 * tmp1_0 + -7 * tmp1_1 + 42 * tmp1_2 + 96 * tmp1_3 + -2 * tmp1_4 + -1 * tmp1_5) + 512) >> 10] + 1) >> 1;
        dst1[3 * dstStride] = ((dst1[3 * dstStride]) + cm[((0 * tmp1_1 + -7 * tmp1_2 + 42 * tmp1_3 + 96 * tmp1_4 + -2 * tmp1_5 + -1 * tmp1_6) + 512) >> 10] + 1) >> 1;
        dst1[4 * dstStride] = ((dst1[4 * dstStride]) + cm[((0 * tmp1_2 + -7 * tmp1_3 + 42 * tmp1_4 + 96 * tmp1_5 + -2 * tmp1_6 + -1 * tmp1_7) + 512) >> 10] + 1) >> 1;
        dst1[5 * dstStride] = ((dst1[5 * dstStride]) + cm[((0 * tmp1_3 + -7 * tmp1_4 + 42 * tmp1_5 + 96 * tmp1_6 + -2 * tmp1_7 + -1 * tmp1_8) + 512) >> 10] + 1) >> 1;
        dst1[6 * dstStride] = ((dst1[6 * dstStride]) + cm[((0 * tmp1_4 + -7 * tmp1_5 + 42 * tmp1_6 + 96 * tmp1_7 + -2 * tmp1_8 + -1 * tmp1_9) + 512) >> 10] + 1) >> 1;
        dst1[7 * dstStride] = ((dst1[7 * dstStride]) + cm[((0 * tmp1_5 + -7 * tmp1_6 + 42 * tmp1_7 + 96 * tmp1_8 + -2 * tmp1_9 + -1 * tmp1_10) + 512) >> 10] + 1) >> 1;
    }

    dst += 2;
    tmp += 2;
}
}
