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

        for (int j = 0; j < 8; j++) {
            int coef = 0;
            int src_val = src2[j * srcStride];
            int dst_val = dst[j * dstStride];
            int cm_index;

            switch (j) {
                case 0: cm_index = 0 * tmpB + -1 * tmpA + 5 * tmp0 + 5 * tmp1 + -1 * tmp2 + 0 * tmp3 + 64 * src_val; break;
                case 1: cm_index = 0 * tmpA + -1 * tmp0 + 5 * tmp1 + 5 * tmp2 + -1 * tmp3 + 0 * tmp4 + 64 * src_val; break;
                case 2: cm_index = 0 * tmp0 + -1 * tmp1 + 5 * tmp2 + 5 * tmp3 + -1 * tmp4 + 0 * tmp5 + 64 * src_val; break;
                case 3: cm_index = 0 * tmp1 + -1 * tmp2 + 5 * tmp3 + 5 * tmp4 + -1 * tmp5 + 0 * tmp6 + 64 * src_val; break;
                case 4: cm_index = 0 * tmp2 + -1 * tmp3 + 5 * tmp4 + 5 * tmp5 + -1 * tmp6 + 0 * tmp7 + 64 * src_val; break;
                case 5: cm_index = 0 * tmp3 + -1 * tmp4 + 5 * tmp5 + 5 * tmp6 + -1 * tmp7 + 0 * tmp8 + 64 * src_val; break;
                case 6: cm_index = 0 * tmp4 + -1 * tmp5 + 5 * tmp6 + 5 * tmp7 + -1 * tmp8 + 0 * tmp9 + 64 * src_val; break;
                case 7: cm_index = 0 * tmp5 + -1 * tmp6 + 5 * tmp7 + 5 * tmp8 + -1 * tmp9 + 0 * tmp10 + 64 * src_val; break;
                default: cm_index = 0; break;
            }

            dst[j * dstStride] = ((dst_val) + cm[(cm_index + 512) >> 10] + 1) >> 1;
        }

        dst++;
        tmp++;
        src2++;
    }
}
