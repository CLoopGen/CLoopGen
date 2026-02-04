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

    // Introduce temporary variables to break direct RAW dependencies and enable reordering
    int val0 = (-1 * tmpA + 5 * tmp0 + 5 * tmp1 -1 * tmp2 + 64 * src2[0 * srcStride]);
    int val1 = (-1 * tmp0 + 5 * tmp1 + 5 * tmp2 -1 * tmp3 + 64 * src2[1 * srcStride]);
    int val2 = (-1 * tmp1 + 5 * tmp2 + 5 * tmp3 -1 * tmp4 + 64 * src2[2 * srcStride]);
    int val3 = (-1 * tmp2 + 5 * tmp3 + 5 * tmp4 -1 * tmp5 + 64 * src2[3 * srcStride]);
    int val4 = (-1 * tmp3 + 5 * tmp4 + 5 * tmp5 -1 * tmp6 + 64 * src2[4 * srcStride]);
    int val5 = (-1 * tmp4 + 5 * tmp5 + 5 * tmp6 -1 * tmp7 + 64 * src2[5 * srcStride]);
    int val6 = (-1 * tmp5 + 5 * tmp6 + 5 * tmp7 -1 * tmp8 + 64 * src2[6 * srcStride]);
    int val7 = (-1 * tmp6 + 5 * tmp7 + 5 * tmp8 -1 * tmp9 + 64 * src2[7 * srcStride]);

    // Store results using precomputed values, removing immediate use after load pattern
    dst[0 * dstStride] = cm[(val0 + 512 + 0 * tmpB + 0 * tmp3) >> 10];
    dst[1 * dstStride] = cm[(val1 + 512 + 0 * tmpA + 0 * tmp4) >> 10];
    dst[2 * dstStride] = cm[(val2 + 512 + 0 * tmp0 + 0 * tmp5) >> 10];
    dst[3 * dstStride] = cm[(val3 + 512 + 0 * tmp1 + 0 * tmp6) >> 10];
    dst[4 * dstStride] = cm[(val4 + 512 + 0 * tmp2 + 0 * tmp7) >> 10];
    dst[5 * dstStride] = cm[(val5 + 512 + 0 * tmp3 + 0 * tmp8) >> 10];
    dst[6 * dstStride] = cm[(val6 + 512 + 0 * tmp4 + 0 * tmp9) >> 10];
    dst[7 * dstStride] = cm[(val7 + 512 + 0 * tmp5 + 0 * tmp10) >> 10];

    // Update pointers after all reads to eliminate WAR hazards from pointer updates
    dst++;
    tmp++;
    src2++;
}
}
