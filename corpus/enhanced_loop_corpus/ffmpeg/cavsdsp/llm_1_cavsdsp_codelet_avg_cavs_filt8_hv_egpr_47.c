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
        for (int k = 0; k < 8; k++) {
            const int idx = tmp[k * 8];
            // Preload necessary tmp values relative to current k
            const int tmpB = (k == 0) ? tmp[-2 * 8] : tmp[(k - 2) * 8];
            const int tmpA = (k == 0) ? tmp[-1 * 8] : tmp[(k - 1) * 8];
            const int tmp0 = (k >= 0 && k < 11) ? tmp[k * 8] : 0;
            const int tmp1 = (k + 1 < 11) ? tmp[(k + 1) * 8] : 0;
            const int tmp2 = (k + 2 < 11) ? tmp[(k + 2) * 8] : 0;
            const int tmp3 = (k + 3 < 11) ? tmp[(k + 3) * 8] : 0;
            const int tmp4 = (k + 4 < 11) ? tmp[(k + 4) * 8] : 0;
            const int tmp5 = (k + 5 < 11) ? tmp[(k + 5) * 8] : 0;
            const int tmp6 = (k + 6 < 11) ? tmp[(k + 6) * 8] : 0;
            const int tmp7 = (k + 7 < 11) ? tmp[(k + 7) * 8] : 0;
            const int tmp8 = (k + 8 < 11) ? tmp[(k + 8) * 8] : 0;
            const int tmp9 = (k + 9 < 11) ? tmp[(k + 9) * 8] : 0;
            const int tmp10 = (k + 10 < 11) ? tmp[(k + 10) * 8] : 0;

            int term0, term1, term2, term3, term4, term5;
            ptrdiff_t src_offset;

            switch (k) {
                case 0: term0 = 0; term1 = -1; term2 = 5; term3 = 5; term4 = -1; term5 = 0; src_offset = 0; break;
                case 1: term0 = 0; term1 = -1; term2 = 5; term3 = 5; term4 = -1; term5 = 0; src_offset = 1; break;
                case 2: term0 = 0; term1 = -1; term2 = 5; term3 = 5; term4 = -1; term5 = 0; src_offset = 2; break;
                case 3: term0 = 0; term1 = -1; term2 = 5; term3 = 5; term4 = -1; term5 = 0; src_offset = 3; break;
                case 4: term0 = 0; term1 = -1; term2 = 5; term3 = 5; term4 = -1; term5 = 0; src_offset = 4; break;
                case 5: term0 = 0; term1 = -1; term2 = 5; term3 = 5; term4 = -1; term5 = 0; src_offset = 5; break;
                case 6: term0 = 0; term1 = -1; term2 = 5; term3 = 5; term4 = -1; term5 = 0; src_offset = 6; break;
                case 7: term0 = 0; term1 = -1; term2 = 5; term3 = 5; term4 = -1; term5 = 0; src_offset = 7; break;
                default: term0 = term1 = term2 = term3 = term4 = term5 = 0; src_offset = 0; break;
            }

            int sum = term0 * tmpB + term1 * tmpA + term2 * tmp0 + term3 * tmp1 +
                      term4 * tmp2 + term5 * tmp3 + 64 * src2[src_offset * srcStride];

            dst[k * dstStride] = ((dst[k * dstStride]) + cm[(sum + 64) >> 7] + 1) >> 1;
        }
        dst++;
        tmp++;
        src2++;
    }
}
