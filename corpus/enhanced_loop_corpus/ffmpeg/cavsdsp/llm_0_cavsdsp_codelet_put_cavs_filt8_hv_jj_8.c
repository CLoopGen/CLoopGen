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
            int coeff = (j == 0) ? tmpB : 
                        (j == 1) ? tmpA :
                        (j == 2) ? tmp0 :
                        (j == 3) ? tmp1 :
                        (j == 4) ? tmp2 :
                        (j == 5) ? tmp3 :
                        (j == 6) ? tmp4 :
                                   tmp5;
            int next = (j <= 2) ? tmp0 :
                       (j == 3) ? tmp1 :
                       (j == 4) ? tmp2 :
                       (j == 5) ? tmp3 :
                       (j == 6) ? tmp4 :
                       (j == 7) ? tmp5 : 0;
            int next2 = (j <= 3) ? tmp1 :
                        (j == 4) ? tmp2 :
                        (j == 5) ? tmp3 :
                        (j == 6) ? tmp4 :
                        (j == 7) ? tmp5 : 0;
            int prev = (j == 0) ? tmpB :
                       (j == 1) ? tmpA :
                       (j >= 2 && j <= 8) ? tmp[j-2] : 0;
            dst[j * dstStride] = cm[((0 * prev + -1 * coeff + 5 * next + 5 * next2 + 
                                      -1 * ((j+1 <= 10) ? tmp[(j+1)*8] : tmp8) + 
                                      0 * ((j+2 <= 10) ? tmp[(j+2)*8] : tmp9) + 
                                      64 * src2[j * srcStride]) + 32) >> 6];
        }
        dst++;
        tmp++;
        src2++;
    }
}
