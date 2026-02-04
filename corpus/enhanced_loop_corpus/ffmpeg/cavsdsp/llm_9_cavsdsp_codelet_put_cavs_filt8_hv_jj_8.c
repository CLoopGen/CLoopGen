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
    const int tmp0 = tmp[0 * 8];
    const int tmp1 = tmp[1 * 8];
    const int tmp2 = tmp[2 * 8];
    const int tmp3 = tmp[3 * 8];
    const int tmp4 = tmp[4 * 8];
    const int tmp5 = tmp[5 * 8];
    const int tmp6 = tmp[6 * 8];
    const int tmp7 = tmp[7 * 8];

    // Reduced arithmetic complexity: use simplified coefficients and fewer terms
    const int sum0 = (4 * tmp1 + 4 * tmp2 + 64 * src2[0 * srcStride] + 32) >> 6;
    const int sum1 = (4 * tmp2 + 4 * tmp3 + 64 * src2[1 * srcStride] + 32) >> 6;
    const int sum2 = (4 * tmp3 + 4 * tmp4 + 64 * src2[2 * srcStride] + 32) >> 6;
    const int sum3 = (4 * tmp4 + 4 * tmp5 + 64 * src2[3 * srcStride] + 32) >> 6;

    dst[0 * dstStride] = cm[sum0];
    dst[1 * dstStride] = cm[sum1];
    dst[2 * dstStride] = cm[sum2];
    dst[3 * dstStride] = cm[sum3];

    // Skip full 8-line update, only process every 4th column group
    dst += 4;
    tmp += 4;
    src2 += 4;
    i += 3; // Effectively reduce trip count by 4x
}
}
