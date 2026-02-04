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

    // Process two rows per iteration to increase computational intensity
    dst[0 * dstStride] = cm[((0 * tmpB + -1 * tmpA + 5 * tmp0 + 5 * tmp1 + -1 * tmp2 + 0 * tmp3 + 64 * src2[0 * srcStride]) + 512) >> 10];
    dst[1 * dstStride] = cm[((0 * tmpA + -1 * tmp0 + 5 * tmp1 + 5 * tmp2 + -1 * tmp3 + 0 * tmp4 + 64 * src2[1 * srcStride]) + 512) >> 10];
    dst[2 * dstStride] = cm[((0 * tmp0 + -1 * tmp1 + 5 * tmp2 + 5 * tmp3 + -1 * tmp4 + 0 * tmp5 + 64 * src2[2 * srcStride]) + 512) >> 10];
    dst[3 * dstStride] = cm[((0 * tmp1 + -1 * tmp2 + 5 * tmp3 + 5 * tmp4 + -1 * tmp5 + 0 * tmp6 + 64 * src2[3 * srcStride]) + 512) >> 10];
    dst[4 * dstStride] = cm[((0 * tmp2 + -1 * tmp3 + 5 * tmp4 + 5 * tmp5 + -1 * tmp6 + 0 * tmp7 + 64 * src2[4 * srcStride]) + 512) >> 10];
    dst[5 * dstStride] = cm[((0 * tmp3 + -1 * tmp4 + 5 * tmp5 + 5 * tmp6 + -1 * tmp7 + 0 * tmp8 + 64 * src2[5 * srcStride]) + 512) >> 10];
    dst[6 * dstStride] = cm[((0 * tmp4 + -1 * tmp5 + 5 * tmp6 + 5 * tmp7 + -1 * tmp8 + 0 * tmp9 + 64 * src2[6 * srcStride]) + 512) >> 10];
    dst[7 * dstStride] = cm[((0 * tmp5 + -1 * tmp6 + 5 * tmp7 + 5 * tmp8 + -1 * tmp9 + 0 * tmp10 + 64 * src2[7 * srcStride]) + 512) >> 10];

    // Second output row using shifted data
    if (i + 1 < w) {
        dst[8 * dstStride] = cm[((0 * tmp6 + -1 * tmp7 + 5 * tmp8 + 5 * tmp9 + -1 * tmp10 + 0 * tmp11 + 64 * src2[8 * srcStride]) + 512) >> 10];
        dst[9 * dstStride] = cm[((0 * tmp7 + -1 * tmp8 + 5 * tmp9 + 5 * tmp10 + -1 * tmp11 + 0 * tmp12 + 64 * src2[9 * srcStride]) + 512) >> 10];
        dst[10 * dstStride] = cm[((0 * tmp8 + -1 * tmp9 + 5 * tmp10 + 5 * tmp11 + -1 * tmp12 + 0 * tmp[13*8] + 64 * src2[10 * srcStride]) + 512) >> 10];
    }

    dst += 2;
    tmp += 2;
    src2 += 2;
}
}
