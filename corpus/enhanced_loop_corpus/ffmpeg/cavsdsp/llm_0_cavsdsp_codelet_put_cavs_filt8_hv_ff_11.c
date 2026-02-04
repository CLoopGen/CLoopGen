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
        for (int j = 0; j < 8; j++) {
            const int tmp_index = tmp[j * 8];
            const int prev1 = (j == 0) ? tmp[-2 * 8] : tmp[(j - 1) * 8];
            const int prev2 = (j == 0) ? tmp[-1 * 8] : (j == 1) ? tmp[-1 * 8] : tmp[(j - 2) * 8];
            const int next = (j + 1 <= 10) ? tmp[(j + 1) * 8] : 0;
            const int next2 = (j + 2 <= 10) ? tmp[(j + 2) * 8] : 0;
            const int src_val = src2[j * srcStride];
            int coeff_sum;

            if (j == 0) {
                coeff_sum = -1 * tmp[-2 * 8] + -2 * tmp[-1 * 8] + 96 * tmp[0 * 8] + 42 * tmp[1 * 8] + -7 * tmp[2 * 8] + 0 * tmp[3 * 8] + 64 * src_val;
            } else {
                coeff_sum = -1 * prev2 + -2 * prev1 + 96 * tmp_index + 42 * next + -7 * next2 + 0 * ((j + 3 <= 10) ? tmp[(j + 3) * 8] : 0) + 64 * src_val;
            }

            dst[j * dstStride] = cm[(coeff_sum + 512) >> 10];
        }
        dst++;
        tmp++;
        src2++;
    }
}
