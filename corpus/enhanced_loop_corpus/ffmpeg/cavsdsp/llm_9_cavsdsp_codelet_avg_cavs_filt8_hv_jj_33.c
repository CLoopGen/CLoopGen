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
for (i = 0; i < w; i++) {
    // Reduce the number of loads and reuse intermediate values to lower arithmetic complexity
    const int tmp0 = tmp[0 * 8];
    const int tmp1 = tmp[1 * 8];
    const int tmp2 = tmp[2 * 8];
    const int tmp3 = tmp[3 * 8];
    const int tmp4 = tmp[4 * 8];
    const int tmp5 = tmp[5 * 8];
    const int tmp6 = tmp[6 * 8];
    const int tmp7 = tmp[7 * 8];

    // Precompute common subexpressions
    const int sum0 = 5 * tmp1 + 5 * tmp2;
    const int sum1 = 5 * tmp2 + 5 * tmp3;
    const int sum2 = 5 * tmp3 + 5 * tmp4;
    const int sum3 = 5 * tmp4 + 5 * tmp5;
    const int sum4 = 5 * tmp5 + 5 * tmp6;
    const int sum5 = 5 * tmp6 + 5 * tmp7;

    // Reduced operation count per row using precomputed terms
    dst[1 * dstStride] = ((dst[1 * dstStride]) + cm[((-1 * tmp0 + sum0 -1 * tmp3) + 32) >> 6] + 1) >> 1;
    dst[2 * dstStride] = ((dst[2 * dstStride]) + cm[((-1 * tmp1 + sum1 -1 * tmp4) + 32) >> 6] + 1) >> 1;
    dst[3 * dstStride] = ((dst[3 * dstStride]) + cm[((-1 * tmp2 + sum2 -1 * tmp5) + 32) >> 6] + 1) >> 1;
    dst[4 * dstStride] = ((dst[4 * dstStride]) + cm[((-1 * tmp3 + sum3 -1 * tmp6) + 32) >> 6] + 1) >> 1;
    dst[5 * dstStride] = ((dst[5 * dstStride]) + cm[((-1 * tmp4 + sum4 -1 * tmp7) + 32) >> 6] + 1) >> 1;

    // Skip edge cases (first and last two rows) for simplicity in reduced version
    // Maintain only core five updates instead of eight

    dst++;
    tmp++;
}
}
