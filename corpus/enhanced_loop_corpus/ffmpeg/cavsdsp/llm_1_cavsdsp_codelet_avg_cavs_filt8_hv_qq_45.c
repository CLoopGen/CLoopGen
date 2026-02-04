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
        for (int k = 0; k < 8; k++) {
            const int idx = (k - 2) * 8;
            const int tmpB = tmp[idx - 2*8];
            const int tmpA = tmp[idx - 1*8];
            const int tmp0 = tmp[idx + 0*8];
            const int tmp1 = tmp[idx + 1*8];
            const int tmp2 = tmp[idx + 2*8];
            const int tmp3 = tmp[idx + 3*8];
            const int tmp4 = tmp[idx + 4*8];
            const int tmp5 = tmp[idx + 5*8];
            const int tmp6 = tmp[idx + 6*8];
            const int tmp7 = tmp[idx + 7*8];
            const int tmp8 = tmp[idx + 8*8];
            const int tmp9 = tmp[idx + 9*8];
            const int tmp10 = tmp[idx + 10*8];

            int sum;
            if (k == 0) sum = 0 * tmpB + -7 * tmpA + 42 * tmp0 + 96 * tmp1 + -2 * tmp2 + -1 * tmp3;
            else if (k == 1) sum = 0 * tmpA + -7 * tmp0 + 42 * tmp1 + 96 * tmp2 + -2 * tmp3 + -1 * tmp4;
            else if (k == 2) sum = 0 * tmp0 + -7 * tmp1 + 42 * tmp2 + 96 * tmp3 + -2 * tmp4 + -1 * tmp5;
            else if (k == 3) sum = 0 * tmp1 + -7 * tmp2 + 42 * tmp3 + 96 * tmp4 + -2 * tmp5 + -1 * tmp6;
            else if (k == 4) sum = 0 * tmp2 + -7 * tmp3 + 42 * tmp4 + 96 * tmp5 + -2 * tmp6 + -1 * tmp7;
            else if (k == 5) sum = 0 * tmp3 + -7 * tmp4 + 42 * tmp5 + 96 * tmp6 + -2 * tmp7 + -1 * tmp8;
            else if (k == 6) sum = 0 * tmp4 + -7 * tmp5 + 42 * tmp6 + 96 * tmp7 + -2 * tmp8 + -1 * tmp9;
            else sum = 0 * tmp5 + -7 * tmp6 + 42 * tmp7 + 96 * tmp8 + -2 * tmp9 + -1 * tmp10;

            dst[k * dstStride] = ((dst[k * dstStride]) + cm[(sum + 512) >> 10] + 1) >> 1;
        }
        dst++;
        tmp++;
    }
}
