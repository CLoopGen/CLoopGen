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

    // Always compute all values, but conditionally write based on index range
    const uint8_t val0 = cm[((0 * tmpB + -1 * tmpA + 5 * tmp0 + 5 * tmp1 + -1 * tmp2 + 0 * tmp3) + 512) >> 10];
    const uint8_t val1 = cm[((0 * tmpA + -1 * tmp0 + 5 * tmp1 + 5 * tmp2 + -1 * tmp3 + 0 * tmp4) + 512) >> 10];
    const uint8_t val2 = cm[((0 * tmp0 + -1 * tmp1 + 5 * tmp2 + 5 * tmp3 + -1 * tmp4 + 0 * tmp5) + 512) >> 10];
    const uint8_t val3 = cm[((0 * tmp1 + -1 * tmp2 + 5 * tmp3 + 5 * tmp4 + -1 * tmp5 + 0 * tmp6) + 512) >> 10];
    const uint8_t val4 = cm[((0 * tmp2 + -1 * tmp3 + 5 * tmp4 + 5 * tmp5 + -1 * tmp6 + 0 * tmp7) + 512) >> 10];
    const uint8_t val5 = cm[((0 * tmp3 + -1 * tmp4 + 5 * tmp5 + 5 * tmp6 + -1 * tmp7 + 0 * tmp8) + 512) >> 10];
    const uint8_t val6 = cm[((0 * tmp4 + -1 * tmp5 + 5 * tmp6 + 5 * tmp7 + -1 * tmp8 + 0 * tmp9) + 512) >> 10];
    const uint8_t val7 = cm[((0 * tmp5 + -1 * tmp6 + 5 * tmp7 + 5 * tmp8 + -1 * tmp9 + 0 * tmp10) + 512) >> 10];

    // Only write results if current index is within a "valid" processing window
    if (i >= 2 && i < w - 2) {
        dst[0 * dstStride] = val0;
        dst[1 * dstStride] = val1;
        dst[2 * dstStride] = val2;
        dst[3 * dstStride] = val3;
        dst[4 * dstStride] = val4;
        dst[5 * dstStride] = val5;
        dst[6 * dstStride] = val6;
        dst[7 * dstStride] = val7;
    } else {
        // Fallback: replicate center value at boundary indices
        dst[0 * dstStride] = cm[(tmp0 + 256) >> 8];
        dst[1 * dstStride] = cm[(tmp1 + 256) >> 8];
        dst[2 * dstStride] = cm[(tmp2 + 256) >> 8];
        dst[3 * dstStride] = cm[(tmp3 + 256) >> 8];
        dst[4 * dstStride] = cm[(tmp4 + 256) >> 8];
        dst[5 * dstStride] = cm[(tmp5 + 256) >> 8];
        dst[6 * dstStride] = cm[(tmp6 + 256) >> 8];
        dst[7 * dstStride] = cm[(tmp7 + 256) >> 8];
    }

    dst++;
    tmp++;
}
}
