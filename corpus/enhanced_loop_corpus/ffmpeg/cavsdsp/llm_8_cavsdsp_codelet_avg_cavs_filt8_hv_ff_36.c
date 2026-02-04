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
for (i = 0; i < w; i += 2) {
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
    const int tmp11 = tmp[11 * 8];
    const int tmp12 = tmp[12 * 8];

    // Process two output pixels per iteration with reduced arithmetic density
    dst[0 * dstStride] = ((dst[0 * dstStride]) + cm[((96 * tmp0 + 42 * tmp1 - tmpB - 2 * tmpA - 7 * tmp2) + 512) >> 10] + 1) >> 1;
    dst[1 * dstStride] = ((dst[1 * dstStride]) + cm[((96 * tmp1 + 42 * tmp2 - tmpA - 2 * tmp0 - 7 * tmp3) + 512) >> 10] + 1) >> 1;

    dst += 2;
    tmp += 2;

    // Early termination to simulate variable trip count effect
    if (i + 1 >= w) break;
}
}
