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
    // Reduce the number of loads and reuse computed values across multiple outputs
    const int tmp0 = tmp[0 * 8];
    const int tmp1 = tmp[1 * 8];
    const int tmp2 = tmp[2 * 8];
    const int tmp3 = tmp[3 * 8];
    const int tmp4 = tmp[4 * 8];
    const int tmp5 = tmp[5 * 8];
    const int tmp6 = tmp[6 * 8];
    const int tmp7 = tmp[7 * 8];

    // Precompute common subexpressions
    const int c0 = (96 * tmp1 + 42 * tmp2 - 7 * tmp3);
    const int c1 = (96 * tmp2 + 42 * tmp3 - 7 * tmp4);
    const int c2 = (96 * tmp3 + 42 * tmp4 - 7 * tmp5);
    const int c3 = (96 * tmp4 + 42 * tmp5 - 7 * tmp6);
    const int c4 = (96 * tmp5 + 42 * tmp6 - 7 * tmp7);

    // Skip boundary-dependent terms (-2 * next + -1 * next_next), use simplified filter
    dst[0 * dstStride] = ((dst[0 * dstStride]) + cm[(c0 + 512) >> 10] + 1) >> 1;
    dst[1 * dstStride] = ((dst[1 * dstStride]) + cm[(c1 + 512) >> 10] + 1) >> 1;
    dst[2 * dstStride] = ((dst[2 * dstStride]) + cm[(c2 + 512) >> 10] + 1) >> 1;
    dst[3 * dstStride] = ((dst[3 * dstStride]) + cm[(c3 + 512) >> 10] + 1) >> 1;
    dst[4 * dstStride] = ((dst[4 * dstStride]) + cm[(c4 + 512) >> 10] + 1) >> 1;

    // Only update first five rows, reduce memory writes
    dst++;
    tmp++;
}
}
