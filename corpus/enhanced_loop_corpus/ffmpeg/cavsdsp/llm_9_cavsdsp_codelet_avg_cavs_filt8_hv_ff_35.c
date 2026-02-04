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
    // Reduce arithmetic complexity by removing less significant terms and simplifying computation
    const int tmp0 = tmp[0 * 8];
    const int tmp1 = tmp[1 * 8];
    const int tmp2 = tmp[2 * 8];
    const int tmp3 = tmp[3 * 8];
    const int tmp4 = tmp[4 * 8];
    const int tmp5 = tmp[5 * 8];
    const int tmp6 = tmp[6 * 8];
    const int tmp7 = tmp[7 * 8];

    // Simplified filter: use only main positive coefficients, drop small negative weights
    dst[0 * dstStride] = ((dst[0 * dstStride]) + cm[(96 * tmp0 + 42 * tmp1 + 64 * src2[0 * srcStride] + 256) >> 9] + 1) >> 1;
    dst[1 * dstStride] = ((dst[1 * dstStride]) + cm[(96 * tmp1 + 42 * tmp2 + 64 * src2[1 * srcStride] + 256) >> 9] + 1) >> 1;
    dst[2 * dstStride] = ((dst[2 * dstStride]) + cm[(96 * tmp2 + 42 * tmp3 + 64 * src2[2 * srcStride] + 256) >> 9] + 1) >> 1;
    dst[3 * dstStride] = ((dst[3 * dstStride]) + cm[(96 * tmp3 + 42 * tmp4 + 64 * src2[3 * srcStride] + 256) >> 9] + 1) >> 1;
    dst[4 * dstStride] = ((dst[4 * dstStride]) + cm[(96 * tmp4 + 42 * tmp5 + 64 * src2[4 * srcStride] + 256) >> 9] + 1) >> 1;
    dst[5 * dstStride] = ((dst[5 * dstStride]) + cm[(96 * tmp5 + 42 * tmp6 + 64 * src2[5 * srcStride] + 256) >> 9] + 1) >> 1;
    dst[6 * dstStride] = ((dst[6 * dstStride]) + cm[(96 * tmp6 + 42 * tmp7 + 64 * src2[6 * srcStride] + 256) >> 9] + 1) >> 1;
    dst[7 * dstStride] = ((dst[7 * dstStride]) + cm[(96 * tmp7 + 64 * src2[7 * srcStride] + 256) >> 9] + 1) >> 1;

    dst++;
    tmp++;
    src2++;
}
}
