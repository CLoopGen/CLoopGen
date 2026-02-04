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
    for (i = 0; i < w; i += 2) {
        for (int k = 0; k < 2 && (i + k) < w; k++) {
            const int idx = i + k;
            const int tmpB = tmp[idx - 2 * 8];
            const int tmpA = tmp[idx - 1 * 8];
            const int tmp0 = tmp[idx + 0 * 8];
            const int tmp1 = tmp[idx + 1 * 8];
            const int tmp2 = tmp[idx + 2 * 8];
            const int tmp3 = tmp[idx + 3 * 8];
            const int tmp4 = tmp[idx + 4 * 8];
            const int tmp5 = tmp[idx + 5 * 8];
            const int tmp6 = tmp[idx + 6 * 8];
            const int tmp7 = tmp[idx + 7 * 8];
            const int tmp8 = tmp[idx + 8 * 8];
            const int tmp9 = tmp[idx + 9 * 8];
            const int tmp10 = tmp[idx + 10 * 8];
            dst[0 * dstStride] = cm[((0 * tmpB + -1 * tmpA + 5 * tmp0 + 5 * tmp1 + -1 * tmp2 + 0 * tmp3 + 64 * src2[0 * srcStride]) + 512) >> 10];
            dst[1 * dstStride] = cm[((0 * tmpA + -1 * tmp0 + 5 * tmp1 + 5 * tmp2 + -1 * tmp3 + 0 * tmp4 + 64 * src2[1 * srcStride]) + 512) >> 10];
            dst[2 * dstStride] = cm[((0 * tmp0 + -1 * tmp1 + 5 * tmp2 + 5 * tmp3 + -1 * tmp4 + 0 * tmp5 + 64 * src2[2 * srcStride]) + 512) >> 10];
            dst[3 * dstStride] = cm[((0 * tmp1 + -1 * tmp2 + 5 * tmp3 + 5 * tmp4 + -1 * tmp5 + 0 * tmp6 + 64 * src2[3 * srcStride]) + 512) >> 10];
            dst[4 * dstStride] = cm[((0 * tmp2 + -1 * tmp3 + 5 * tmp4 + 5 * tmp5 + -1 * tmp6 + 0 * tmp7 + 64 * src2[4 * srcStride]) + 512) >> 10];
            dst[5 * dstStride] = cm[((0 * tmp3 + -1 * tmp4 + 5 * tmp5 + 5 * tmp6 + -1 * tmp7 + 0 * tmp8 + 64 * src2[5 * srcStride]) + 512) >> 10];
            dst[6 * dstStride] = cm[((0 * tmp4 + -1 * tmp5 + 5 * tmp6 + 5 * tmp7 + -1 * tmp8 + 0 * tmp9 + 64 * src2[6 * srcStride]) + 512) >> 10];
            dst[7 * dstStride] = cm[((0 * tmp5 + -1 * tmp6 + 5 * tmp7 + 5 * tmp8 + -1 * tmp9 + 0 * tmp10 + 64 * src2[7 * srcStride]) + 512) >> 10];
            dst++;
            tmp++;
            src2++;
        }
    }
}
