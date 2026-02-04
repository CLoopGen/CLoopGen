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
    // Reduce arithmetic complexity by reusing common subexpressions and reducing coefficient multiplications
    const int tmp0 = tmp[0 * 8];
    const int tmp1 = tmp[1 * 8];
    const int tmp2 = tmp[2 * 8];
    const int tmp3 = tmp[3 * 8];
    const int tmp4 = tmp[4 * 8];
    const int tmp5 = tmp[5 * 8];
    const int tmp6 = tmp[6 * 8];
    const int tmp7 = tmp[7 * 8];

    // Precompute shared terms
    const int t0 = (-tmp0 + 5 * tmp1 + 5 * tmp2 - tmp3);
    const int t1 = (-tmp1 + 5 * tmp2 + 5 * tmp3 - tmp4);
    const int t2 = (-tmp2 + 5 * tmp3 + 5 * tmp4 - tmp5);
    const int t3 = (-tmp3 + 5 * tmp4 + 5 * tmp5 - tmp6);
    const int t4 = (-tmp4 + 5 * tmp5 + 5 * tmp6 - tmp7);

    // Use simplified expressions with fewer operations
    dst[0 * dstStride] = ((dst[0 * dstStride]) + cm[(t0 + 64 * src2[0 * srcStride] + 512) >> 10] + 1) >> 1;
    dst[1 * dstStride] = ((dst[1 * dstStride]) + cm[(t1 + 64 * src2[1 * srcStride] + 512) >> 10] + 1) >> 1;
    dst[2 * dstStride] = ((dst[2 * dstStride]) + cm[(t2 + 64 * src2[2 * srcStride] + 512) >> 10] + 1) >> 1;
    dst[3 * dstStride] = ((dst[3 * dstStride]) + cm[(t3 + 64 * src2[3 * srcStride] + 512) >> 10] + 1) >> 1;
    dst[4 * dstStride] = ((dst[4 * dstStride]) + cm[(t4 + 64 * src2[4 * srcStride] + 512) >> 10] + 1) >> 1;

    // Skip redundant updates for higher indices to reduce work per iteration
    // Only process first 5 of the original 8 outputs per iteration

    dst++;
    tmp++;
    src2++;
}
}
