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
            int coef0, coef1, coef2, coef3, coef4, coef5;
            uint8_t* src_val;

            switch (j) {
                case 0: coef0 = 0; coef1 = -1; coef2 = 5; coef3 = 5; coef4 = -1; coef5 = 0; src_val = &src2[0 * srcStride]; break;
                case 1: coef0 = 0; coef1 = -1; coef2 = 5; coef3 = 5; coef4 = -1; coef5 = 0; src_val = &src2[1 * srcStride]; break;
                case 2: coef0 = 0; coef1 = -1; coef2 = 5; coef3 = 5; coef4 = -1; coef5 = 0; src_val = &src2[2 * srcStride]; break;
                case 3: coef0 = 0; coef1 = -1; coef2 = 5; coef3 = 5; coef4 = -1; coef5 = 0; src_val = &src2[3 * srcStride]; break;
                case 4: coef0 = 0; coef1 = -1; coef2 = 5; coef3 = 5; coef4 = -1; coef5 = 0; src_val = &src2[4 * srcStride]; break;
                case 5: coef0 = 0; coef1 = -1; coef2 = 5; coef3 = 5; coef4 = -1; coef5 = 0; src_val = &src2[5 * srcStride]; break;
                case 6: coef0 = 0; coef1 = -1; coef2 = 5; coef3 = 5; coef4 = -1; coef5 = 0; src_val = &src2[6 * srcStride]; break;
                case 7: coef0 = 0; coef1 = -1; coef2 = 5; coef3 = 5; coef4 = -1; coef5 = 0; src_val = &src2[7 * srcStride]; break;
            }

            const int* base_tmp = &tmp0;
            int sum = coef0 * base_tmp[j-2] + coef1 * base_tmp[j-1] + coef2 * base_tmp[j+0] +
                      coef3 * base_tmp[j+1] + coef4 * base_tmp[j+2] + coef5 * base_tmp[j+3] +
                      64 * (*src_val);

            dst[j * dstStride] = ((dst[j * dstStride]) + cm[(sum + 64) >> 7] + 1) >> 1;
        }

        dst++;
        tmp++;
        src2++;
    }
}
