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

    int processed_count = 0;

    // Control dependency: only process first N elements based on runtime condition
    const int limit = (w > 4) ? 4 : w; // Cap updates to avoid out-of-bounds or reduce work

    for (int j = 0; j < limit; j++) {
        const int coeff = (j == 0) ? (0 * tmpB + -7 * tmpA + 42 * tmp0 + 96 * tmp1 + -2 * tmp2 + -1 * tmp3 + 64 * src2[0 * srcStride]) :
                          (j == 1) ? (0 * tmpA + -7 * tmp0 + 42 * tmp1 + 96 * tmp2 + -2 * tmp3 + -1 * tmp4 + 64 * src2[1 * srcStride]) :
                          (j == 2) ? (0 * tmp0 + -7 * tmp1 + 42 * tmp2 + 96 * tmp3 + -2 * tmp4 + -1 * tmp5 + 64 * src2[2 * srcStride]) :
                                     (0 * tmp1 + -7 * tmp2 + 42 * tmp3 + 96 * tmp4 + -2 * tmp5 + -1 * tmp6 + 64 * src2[3 * srcStride]);

        dst[j * dstStride] = ((dst[j * dstStride]) + cm[(coeff + 512) >> 10] + 1) >> 1;
        processed_count++;
    }

    // Conditional full update only if threshold met
    if (processed_count < 4 && i % 2 == 0) {
        // Fallback unrolled update for even indices
        dst[4 * dstStride] = ((dst[4 * dstStride]) + cm[((0 * tmp2 + -7 * tmp3 + 42 * tmp4 + 96 * tmp5 + -2 * tmp6 + -1 * tmp7 + 64 * src2[4 * srcStride]) + 512) >> 10] + 1) >> 1;
        dst[5 * dstStride] = ((dst[5 * dstStride]) + cm[((0 * tmp3 + -7 * tmp4 + 42 * tmp5 + 96 * tmp6 + -2 * tmp7 + -1 * tmp8 + 64 * src2[5 * srcStride]) + 512) >> 10] + 1) >> 1;
    }

    dst++;
    tmp++;
    src2++;
}
}
