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
// Eliminate loop-carried dependency on `tmp` and `src2` by unrolling two iterations and interleaving
int limit = w - 1;
for (i = 0; i < limit; i += 2) {
    // Load data for current and next iteration upfront
    const int cur_tmpB = tmp[-2 * 8];
    const int cur_tmpA = tmp[-1 * 8];
    const int cur_tmp0 = tmp[0 * 8];
    const int cur_tmp1 = tmp[1 * 8];
    const int cur_tmp2 = tmp[2 * 8];
    const int cur_tmp3 = tmp[3 * 8];
    const int cur_tmp4 = tmp[4 * 8];
    const int cur_tmp5 = tmp[5 * 8];
    const int cur_tmp6 = tmp[6 * 8];
    const int cur_tmp7 = tmp[7 * 8];
    const int cur_tmp8 = tmp[8 * 8];
    const int cur_tmp9 = tmp[9 * 8];
    const int cur_tmp10 = tmp[10 * 8];

    const int nxt_tmpA = tmp[1 * 8];  // Shifted: next iteration's tmp[-1*8]
    const int nxt_tmp0 = tmp[2 * 8];
    const int nxt_tmp1 = tmp[3 * 8];
    const int nxt_tmp2 = tmp[4 * 8];
    const int nxt_tmp3 = tmp[5 * 8];
    const int nxt_tmp4 = tmp[6 * 8];
    const int nxt_tmp5 = tmp[7 * 8];
    const int nxt_tmp6 = tmp[8 * 8];
    const int nxt_tmp7 = tmp[9 * 8];
    const int nxt_tmp8 = tmp[10 * 8];
    const int nxt_tmp9 = tmp[11 * 8];
    const int nxt_tmp10 = tmp[12 * 8];
    const int nxt_tmp11 = tmp[13 * 8];

    // Compute current iteration
    dst[0 * dstStride] = ((dst[0 * dstStride]) + cm[((0 * cur_tmpB + -1 * cur_tmpA + 5 * cur_tmp0 + 5 * cur_tmp1 + -1 * cur_tmp2 + 0 * cur_tmp3 + 64 * src2[0 * srcStride]) + 512) >> 10] + 1) >> 1;
    dst[1 * dstStride] = ((dst[1 * dstStride]) + cm[((0 * cur_tmpA + -1 * cur_tmp0 + 5 * cur_tmp1 + 5 * cur_tmp2 + -1 * cur_tmp3 + 0 * cur_tmp4 + 64 * src2[1 * srcStride]) + 512) >> 10] + 1) >> 1;
    dst[2 * dstStride] = ((dst[2 * dstStride]) + cm[((0 * cur_tmp0 + -1 * cur_tmp1 + 5 * cur_tmp2 + 5 * cur_tmp3 + -1 * cur_tmp4 + 0 * cur_tmp5 + 64 * src2[2 * srcStride]) + 512) >> 10] + 1) >> 1;
    dst[3 * dstStride] = ((dst[3 * dstStride]) + cm[((0 * cur_tmp1 + -1 * cur_tmp2 + 5 * cur_tmp3 + 5 * cur_tmp4 + -1 * cur_tmp5 + 0 * cur_tmp6 + 64 * src2[3 * srcStride]) + 512) >> 10] + 1) >> 1;
    dst[4 * dstStride] = ((dst[4 * dstStride]) + cm[((0 * cur_tmp2 + -1 * cur_tmp3 + 5 * cur_tmp4 + 5 * cur_tmp5 + -1 * cur_tmp6 + 0 * cur_tmp7 + 64 * src2[4 * srcStride]) + 512) >> 10] + 1) >> 1;
    dst[5 * dstStride] = ((dst[5 * dstStride]) + cm[((0 * cur_tmp3 + -1 * cur_tmp4 + 5 * cur_tmp5 + 5 * cur_tmp6 + -1 * cur_tmp7 + 0 * cur_tmp8 + 64 * src2[5 * srcStride]) + 512) >> 10] + 1) >> 1;
    dst[6 * dstStride] = ((dst[6 * dstStride]) + cm[((0 * cur_tmp4 + -1 * cur_tmp5 + 5 * cur_tmp6 + 5 * cur_tmp7 + -1 * cur_tmp8 + 0 * cur_tmp9 + 64 * src2[6 * srcStride]) + 512) >> 10] + 1) >> 1;
    dst[7 * dstStride] = ((dst[7 * dstStride]) + cm[((0 * cur_tmp5 + -1 * cur_tmp6 + 5 * cur_tmp7 + 5 * cur_tmp8 + -1 * cur_tmp9 + 0 * cur_tmp10 + 64 * src2[7 * srcStride]) + 512) >> 10] + 1) >> 1;

    // Compute next iteration using offset data
    uint8_t* next_dst = dst + 1;
    next_dst[0 * dstStride] = ((next_dst[0 * dstStride]) + cm[((0 * cur_tmpA + -1 * cur_tmp0 + 5 * cur_tmp1 + 5 * cur_tmp2 + -1 * cur_tmp3 + 0 * cur_tmp4 + 64 * src2[1 * srcStride]) + 512) >> 10] + 1) >> 1;
    next_dst[1 * dstStride] = ((next_dst[1 * dstStride]) + cm[((0 * cur_tmp0 + -1 * cur_tmp1 + 5 * cur_tmp2 + 5 * cur_tmp3 + -1 * cur_tmp4 + 0 * cur_tmp5 + 64 * src2[2 * srcStride]) + 512) >> 10] + 1) >> 1;
    next_dst[2 * dstStride] = ((next_dst[2 * dstStride]) + cm[((0 * cur_tmp1 + -1 * cur_tmp2 + 5 * cur_tmp3 + 5 * cur_tmp4 + -1 * cur_tmp5 + 0 * cur_tmp6 + 64 * src2[3 * srcStride]) + 512) >> 10] + 1) >> 1;
    next_dst[3 * dstStride] = ((next_dst[3 * dstStride]) + cm[((0 * cur_tmp2 + -1 * cur_tmp3 + 5 * cur_tmp4 + 5 * cur_tmp5 + -1 * cur_tmp6 + 0 * cur_tmp7 + 64 * src2[4 * srcStride]) + 512) >> 10] + 1) >> 1;
    next_dst[4 * dstStride] = ((next_dst[4 * dstStride]) + cm[((0 * cur_tmp3 + -1 * cur_tmp4 + 5 * cur_tmp5 + 5 * cur_tmp6 + -1 * cur_tmp7 + 0 * cur_tmp8 + 64 * src2[5 * srcStride]) + 512) >> 10] + 1) >> 1;
    next_dst[5 * dstStride] = ((next_dst[5 * dstStride]) + cm[((0 * cur_tmp4 + -1 * cur_tmp5 + 5 * cur_tmp6 + 5 * cur_tmp7 + -1 * cur_tmp8 + 0 * cur_tmp9 + 64 * src2[6 * srcStride]) + 512) >> 10] + 1) >> 1;
    next_dst[6 * dstStride] = ((next_dst[6 * dstStride]) + cm[((0 * cur_tmp5 + -1 * cur_tmp6 + 5 * cur_tmp7 + 5 * cur_tmp8 + -1 * cur_tmp9 + 0 * cur_tmp10 + 64 * src2[7 * srcStride]) + 512) >> 10] + 1) >> 1;
    next_dst[7 * dstStride] = ((next_dst[7 * dstStride]) + cm[((0 * cur_tmp6 + -1 * cur_tmp7 + 5 * cur_tmp8 + 5 * cur_tmp9 + -1 * cur_tmp10 + 0 * nxt_tmp11 + 64 * (src2[1] + 1)) + 512) >> 10] + 1) >> 1;

    // Stride updates for two steps
    dst += 2;
    tmp += 2;
    src2 += 2;
}

// Handle remaining odd iteration if needed
if (i < w) {
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
    dst[0 * dstStride] = ((dst[0 * dstStride]) + cm[((0 * tmpB + -1 * tmpA + 5 * tmp0 + 5 * tmp1 + -1 * tmp2 + 0 * tmp3 + 64 * src2[0 * srcStride]) + 512) >> 10] + 1) >> 1;
    dst[1 * dstStride] = ((dst[1 * dstStride]) + cm[((0 * tmpA + -1 * tmp0 + 5 * tmp1 + 5 * tmp2 + -1 * tmp3 + 0 * tmp4 + 64 * src2[1 * srcStride]) + 512) >> 10] + 1) >> 1;
    dst[2 * dstStride] = ((dst[2 * dstStride]) + cm[((0 * tmp0 + -1 * tmp1 + 5 * tmp2 + 5 * tmp3 + -1 * tmp4 + 0 * tmp5 + 64 * src2[2 * srcStride]) + 512) >> 10] + 1) >> 1;
    dst[3 * dstStride] = ((dst[3 * dstStride]) + cm[((0 * tmp1 + -1 * tmp2 + 5 * tmp3 + 5 * tmp4 + -1 * tmp5 + 0 * tmp6 + 64 * src2[3 * srcStride]) + 512) >> 10] + 1) >> 1;
    dst[4 * dstStride] = ((dst[4 * dstStride]) + cm[((0 * tmp2 + -1 * tmp3 + 5 * tmp4 + 5 * tmp5 + -1 * tmp6 + 0 * tmp7 + 64 * src2[4 * srcStride]) + 512) >> 10] + 1) >> 1;
    dst[5 * dstStride] = ((dst[5 * dstStride]) + cm[((0 * tmp3 + -1 * tmp4 + 5 * tmp5 + 5 * tmp6 + -1 * tmp7 + 0 * tmp8 + 64 * src2[5 * srcStride]) + 512) >> 10] + 1) >> 1;
    dst[6 * dstStride] = ((dst[6 * dstStride]) + cm[((0 * tmp4 + -1 * tmp5 + 5 * tmp6 + 5 * tmp7 + -1 * tmp8 + 0 * tmp9 + 64 * src2[6 * srcStride]) + 512) >> 10] + 1) >> 1;
    dst[7 * dstStride] = ((dst[7 * dstStride]) + cm[((0 * tmp5 + -1 * tmp6 + 5 * tmp7 + 5 * tmp8 + -1 * tmp9 + 0 * tmp10 + 64 * src2[7 * srcStride]) + 512) >> 10] + 1) >> 1;
    dst++;
    tmp++;
    src2++;
}
}
