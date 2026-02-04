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



void loop() {
    for (i = 0; i < w; i++) {
        for (int k = 0; k < 8; k++) {
            const int idx = k - 2;
            const int tmpB = tmp[idx * 8 - 2 * 8];
            const int tmpA = tmp[idx * 8 - 1 * 8];
            const int tmp0 = tmp[idx * 8 + 0 * 8];
            const int tmp1 = tmp[idx * 8 + 1 * 8];
            const int tmp2 = tmp[idx * 8 + 2 * 8];
            const int tmp3 = tmp[idx * 8 + 3 * 8];
            const int tmp4 = tmp[idx * 8 + 4 * 8];
            const int tmp5 = tmp[idx * 8 + 5 * 8];
            const int tmp6 = tmp[idx * 8 + 6 * 8];
            const int tmp7 = tmp[idx * 8 + 7 * 8];
            const int tmp8 = tmp[idx * 8 + 8 * 8];
            const int tmp9 = tmp[idx * 8 + 9 * 8];
            const int tmp10 = tmp[idx * 8 + 10 * 8];

            int coeff = 0;
            if (k == 0) coeff = 0 * tmpB + -1 * tmpA + 5 * tmp0 + 5 * tmp1 + -1 * tmp2 + 0 * tmp3;
            else if (k == 1) coeff = 0 * tmpA + -1 * tmp0 + 5 * tmp1 + 5 * tmp2 + -1 * tmp3 + 0 * tmp4;
            else if (k == 2) coeff = 0 * tmp0 + -1 * tmp1 + 5 * tmp2 + 5 * tmp3 + -1 * tmp4 + 0 * tmp5;
            else if (k == 3) coeff = 0 * tmp1 + -1 * tmp2 + 5 * tmp3 + 5 * tmp4 + -1 * tmp5 + 0 * tmp6;
            else if (k == 4) coeff = 0 * tmp2 + -1 * tmp3 + 5 * tmp4 + 5 * tmp5 + -1 * tmp6 + 0 * tmp7;
            else if (k == 5) coeff = 0 * tmp3 + -1 * tmp4 + 5 * tmp5 + 5 * tmp6 + -1 * tmp7 + 0 * tmp8;
            else if (k == 6) coeff = 0 * tmp4 + -1 * tmp5 + 5 * tmp6 + 5 * tmp7 + -1 * tmp8 + 0 * tmp9;
            else if (k == 7) coeff = 0 * tmp5 + -1 * tmp6 + 5 * tmp7 + 5 * tmp8 + -1 * tmp9 + 0 * tmp10;

            dst[k * dstStride] = cm[(coeff + 64 * src2[k * srcStride] + 64) >> 7];
        }
        dst++;
        tmp++;
        src2++;
    }
}
