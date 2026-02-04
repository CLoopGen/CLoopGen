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
    const int tmp11 = tmp[11 * 8];
    const int tmp12 = tmp[12 * 8];

    // Process two outputs per iteration to increase computational intensity
    dst[0 * dstStride] = cm[((0 * tmpB + -7 * tmpA + 42 * tmp0 + 96 * tmp1 + -2 * tmp2 + -1 * tmp3 + 64 * src2[0 * srcStride]) + 512) >> 10];
    dst[1 * dstStride] = cm[((0 * tmpA + -7 * tmp0 + 42 * tmp1 + 96 * tmp2 + -2 * tmp3 + -1 * tmp4 + 64 * src2[1 * srcStride]) + 512) >> 10];
    dst[2 * dstStride] = cm[((0 * tmp0 + -7 * tmp1 + 42 * tmp2 + 96 * tmp3 + -2 * tmp4 + -1 * tmp5 + 64 * src2[2 * srcStride]) + 512) >> 10];
    dst[3 * dstStride] = cm[((0 * tmp1 + -7 * tmp2 + 42 * tmp3 + 96 * tmp4 + -2 * tmp5 + -1 * tmp6 + 64 * src2[3 * srcStride]) + 512) >> 10];
    dst[4 * dstStride] = cm[((0 * tmp2 + -7 * tmp3 + 42 * tmp4 + 96 * tmp5 + -2 * tmp6 + -1 * tmp7 + 64 * src2[4 * srcStride]) + 512) >> 10];
    dst[5 * dstStride] = cm[((0 * tmp3 + -7 * tmp4 + 42 * tmp5 + 96 * tmp6 + -2 * tmp7 + -1 * tmp8 + 64 * src2[5 * srcStride]) + 512) >> 10];
    dst[6 * dstStride] = cm[((0 * tmp4 + -7 * tmp5 + 42 * tmp6 + 96 * tmp7 + -2 * tmp8 + -1 * tmp9 + 64 * src2[6 * srcStride]) + 512) >> 10];
    dst[7 * dstStride] = cm[((0 * tmp5 + -7 * tmp6 + 42 * tmp7 + 96 * tmp8 + -2 * tmp9 + -1 * tmp10 + 64 * src2[7 * srcStride]) + 512) >> 10];

    // Second vector output using shifted window
    if (i + 1 < w) {
        dst[8 * dstStride] = cm[((0 * tmp6 + -7 * tmp7 + 42 * tmp8 + 96 * tmp9 + -2 * tmp10 + -1 * tmp11 + 64 * src2[8 * srcStride]) + 512) >> 10];
        dst[9 * dstStride] = cm[((0 * tmp7 + -7 * tmp8 + 42 * tmp9 + 96 * tmp10 + -2 * tmp11 + -1 * tmp12 + 64 * src2[9 * srcStride]) + 512) >> 10];
        dst[10 * dstStride] = cm[((0 * tmp8 + -7 * tmp9 + 42 * tmp10 + 96 * tmp11 + -2 * tmp12 + -1 * tmp[13 * 8] + 64 * src2[10 * srcStride]) + 512) >> 10];
        dst += 2;
        tmp += 2;
        src2 += 2;
    } else {
        dst++;
        tmp++;
        src2++;
    }
}
}
