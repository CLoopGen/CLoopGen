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

    // Introduce temporary accumulators to modify RAW/WAW dependencies
    int acc0 = (-1 * tmpB + -2 * tmpA + 96 * tmp0 + 42 * tmp1 + -7 * tmp2 + 0 * tmp3) + 512;
    int acc1 = (-1 * tmpA + -2 * tmp0 + 96 * tmp1 + 42 * tmp2 + -7 * tmp3 + 0 * tmp4) + 512;
    int acc2 = (-1 * tmp0 + -2 * tmp1 + 96 * tmp2 + 42 * tmp3 + -7 * tmp4 + 0 * tmp5) + 512;
    int acc3 = (-1 * tmp1 + -2 * tmp2 + 96 * tmp3 + 42 * tmp4 + -7 * tmp5 + 0 * tmp6) + 512;
    int acc4 = (-1 * tmp2 + -2 * tmp3 + 96 * tmp4 + 42 * tmp5 + -7 * tmp6 + 0 * tmp7) + 512;
    int acc5 = (-1 * tmp3 + -2 * tmp4 + 96 * tmp5 + 42 * tmp6 + -7 * tmp7 + 0 * tmp8) + 512;
    int acc6 = (-1 * tmp4 + -2 * tmp5 + 96 * tmp6 + 42 * tmp7 + -7 * tmp8 + 0 * tmp9) + 512;
    int acc7 = (-1 * tmp5 + -2 * tmp6 + 96 * tmp7 + 42 * tmp8 + -7 * tmp9 + 0 * tmp10) + 512;

    // Use intermediate values to break direct computation-to-store dependency
    uint8_t val0 = cm[acc0 >> 10];
    uint8_t val1 = cm[acc1 >> 10];
    uint8_t val2 = cm[acc2 >> 10];
    uint8_t val3 = cm[acc3 >> 10];
    uint8_t val4 = cm[acc4 >> 10];
    uint8_t val5 = cm[acc5 >> 10];
    uint8_t val6 = cm[acc6 >> 10];
    uint8_t val7 = cm[acc7 >> 10];

    // Reorder updates to reduce WAW hazards and allow pipelining
    dst[0 * dstStride] = ((dst[0 * dstStride]) + val0 + 1) >> 1;
    dst[1 * dstStride] = ((dst[1 * dstStride]) + val1 + 1) >> 1;
    dst[2 * dstStride] = ((dst[2 * dstStride]) + val2 + 1) >> 1;
    dst[3 * dstStride] = ((dst[3 * dstStride]) + val3 + 1) >> 1;
    dst[4 * dstStride] = ((dst[4 * dstStride]) + val4 + 1) >> 1;
    dst[5 * dstStride] = ((dst[5 * dstStride]) + val5 + 1) >> 1;
    dst[6 * dstStride] = ((dst[6 * dstStride]) + val6 + 1) >> 1;
    dst[7 * dstStride] = ((dst[7 * dstStride]) + val7 + 1) >> 1;

    dst++;
    tmp++;
}
}
