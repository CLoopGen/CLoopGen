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
for (i = 0; i < w; i++) {
    // Early exit condition introduced: skip processing when tmp values meet a threshold
    const int tmp0 = tmp[0 * 8];
    const int tmp7 = tmp[7 * 8];
    if (tmp0 < 16 && tmp7 > 240) {
        dst++;
        tmp++;
        src2++;
        continue; // Skip complex computation for out-of-range data
    }

    const int tmpB = tmp[-2 * 8];
    const int tmpA = tmp[-1 * 8];
    const int tmp1 = tmp[1 * 8];
    const int tmp2 = tmp[2 * 8];
    const int tmp3 = tmp[3 * 8];
    const int tmp4 = tmp[4 * 8];
    const int tmp5 = tmp[5 * 8];
    const int tmp6 = tmp[6 * 8];
    const int tmp8 = tmp[8 * 8];
    const int tmp9 = tmp[9 * 8];
    const int tmp10 = tmp[10 * 8];

    // Compute all outputs unconditionally after filter pass
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
