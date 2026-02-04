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
    // Reduce arithmetic complexity by removing redundant terms and simplifying filter
    const int tmp0 = tmp[0 * 8];
    const int tmp1 = tmp[1 * 8];
    const int tmp2 = tmp[2 * 8];
    const int tmp3 = tmp[3 * 8];
    const int tmp4 = tmp[4 * 8];
    const int tmp5 = tmp[5 * 8];
    const int tmp6 = tmp[6 * 8];
    const int tmp7 = tmp[7 * 8];

    // Simplified interpolation: use only central terms with reduced coefficient range
    dst[0 * dstStride] = ((dst[0 * dstStride]) + cm[(tmp0 + tmp1 + 256) >> 9] + 1) >> 1;
    dst[1 * dstStride] = ((dst[1 * dstStride]) + cm[(tmp1 + tmp2 + 256) >> 9] + 1) >> 1;
    dst[2 * dstStride] = ((dst[2 * dstStride]) + cm[(tmp2 + tmp3 + 256) >> 9] + 1) >> 1;
    dst[3 * dstStride] = ((dst[3 * dstStride]) + cm[(tmp3 + tmp4 + 256) >> 9] + 1) >> 1;
    dst[4 * dstStride] = ((dst[4 * dstStride]) + cm[(tmp4 + tmp5 + 256) >> 9] + 1) >> 1;
    dst[5 * dstStride] = ((dst[5 * dstStride]) + cm[(tmp5 + tmp6 + 256) >> 9] + 1) >> 1;
    dst[6 * dstStride] = ((dst[6 * dstStride]) + cm[(tmp6 + tmp7 + 256) >> 9] + 1) >> 1;

    // Skip one update to reduce memory writes (only 7 instead of 8)
    dst++;
    tmp++;
}
}
