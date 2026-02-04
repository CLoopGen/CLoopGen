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
        const int idx_base = i * 8;
        const int tmp_indices[] = {
            tmp[-2 * 8], tmp[-1 * 8], tmp[0 * 8], tmp[1 * 8], tmp[2 * 8],
            tmp[3 * 8], tmp[4 * 8], tmp[5 * 8], tmp[6 * 8], tmp[7 * 8],
            tmp[8 * 8], tmp[9 * 8], tmp[10 * 8]
        };
        const int tmpB = tmp_indices[0];
        const int tmpA = tmp_indices[1];
        const int tmp0 = tmp_indices[2];
        const int tmp1 = tmp_indices[3];
        const int tmp2 = tmp_indices[4];
        const int tmp3 = tmp_indices[5];
        const int tmp4 = tmp_indices[6];
        const int tmp5 = tmp_indices[7];
        const int tmp6 = tmp_indices[8];
        const int tmp7 = tmp_indices[9];
        const int tmp8 = tmp_indices[10];
        const int tmp9 = tmp_indices[11];
        const int tmp10 = tmp_indices[12];

        ptrdiff_t k;
        for (k = 0; k < 8; k++) {
            const int coeff[] = {0, -1, 5, 5, -1, 0};
            const int *tref[] = { &tmpB, &tmpA, &tmp0, &tmp1, &tmp2, &tmp3, &tmp4, &tmp5, &tmp6, &tmp7, &tmp8, &tmp9, &tmp10 };
            const int t0 = (k >= 1) ? *(tref[k-1+1]) : 0;
            const int t1 = *(tref[k+1]);
            const int t2 = *(tref[k+2]);
            const int t3 = *(tref[k+3]);
            const int t4 = *(tref[k+4]);
            const int t5 = (k <= 7) ? *(tref[k+5]) : 0;

            const int sum = coeff[0]*t0 + coeff[1]*t1 + coeff[2]*t2 + coeff[3]*t3 + coeff[4]*t4 + coeff[5]*t5 + 64 * src2[k * srcStride];
            dst[k * dstStride] = ((dst[k * dstStride]) + cm[(sum + 32) >> 6] + 1) >> 1;
        }

        dst++;
        tmp++;
        src2++;
    }
}
