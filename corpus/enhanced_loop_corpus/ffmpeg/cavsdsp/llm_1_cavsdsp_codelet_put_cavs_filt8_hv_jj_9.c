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
        for (int step = 0; step < 2 && (i + step) < w; step++) {
            const int idx = i + step;
            const int tmpB = tmp[step - 2 * 8];
            const int tmpA = tmp[step - 1 * 8];
            const int tmp0 = tmp[step + 0 * 8];
            const int tmp1 = tmp[step + 1 * 8];
            const int tmp2 = tmp[step + 2 * 8];
            const int tmp3 = tmp[step + 3 * 8];
            const int tmp4 = tmp[step + 4 * 8];
            const int tmp5 = tmp[step + 5 * 8];
            const int tmp6 = tmp[step + 6 * 8];
            const int tmp7 = tmp[step + 7 * 8];
            const int tmp8 = tmp[step + 8 * 8];
            const int tmp9 = tmp[step + 9 * 8];
            const int tmp10 = tmp[step + 10 * 8];
            dst[0 * dstStride] = cm[((0 * tmpB + -1 * tmpA + 5 * tmp0 + 5 * tmp1 + -1 * tmp2 + 0 * tmp3) + 32) >> 6];
            dst[1 * dstStride] = cm[((0 * tmpA + -1 * tmp0 + 5 * tmp1 + 5 * tmp2 + -1 * tmp3 + 0 * tmp4) + 32) >> 6];
            dst[2 * dstStride] = cm[((0 * tmp0 + -1 * tmp1 + 5 * tmp2 + 5 * tmp3 + -1 * tmp4 + 0 * tmp5) + 32) >> 6];
            dst[3 * dstStride] = cm[((0 * tmp1 + -1 * tmp2 + 5 * tmp3 + 5 * tmp4 + -1 * tmp5 + 0 * tmp6) + 32) >> 6];
            dst[4 * dstStride] = cm[((0 * tmp2 + -1 * tmp3 + 5 * tmp4 + 5 * tmp5 + -1 * tmp6 + 0 * tmp7) + 32) >> 6];
            dst[5 * dstStride] = cm[((0 * tmp3 + -1 * tmp4 + 5 * tmp5 + 5 * tmp6 + -1 * tmp7 + 0 * tmp8) + 32) >> 6];
            dst[6 * dstStride] = cm[((0 * tmp4 + -1 * tmp5 + 5 * tmp6 + 5 * tmp7 + -1 * tmp8 + 0 * tmp9) + 32) >> 6];
            dst[7 * dstStride] = cm[((0 * tmp5 + -1 * tmp6 + 5 * tmp7 + 5 * tmp8 + -1 * tmp9 + 0 * tmp10) + 32) >> 6];
            dst++;
            tmp++;
        }
    }
}
