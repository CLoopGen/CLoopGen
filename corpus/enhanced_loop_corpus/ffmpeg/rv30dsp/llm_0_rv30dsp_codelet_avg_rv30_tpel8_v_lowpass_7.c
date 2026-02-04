#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  uint8_t *src;
extern int dstStride;
extern int srcStride;
extern  int C1;
extern  int C2;
extern  int w;
extern  uint8_t *cm;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < w; i++) {
        const int srcA = src[-1 * srcStride];
        const int src0 = src[0 * srcStride];
        const int src1 = src[1 * srcStride];
        const int src2 = src[2 * srcStride];
        const int src3 = src[3 * srcStride];
        const int src4 = src[4 * srcStride];
        const int src5 = src[5 * srcStride];
        const int src6 = src[6 * srcStride];
        const int src7 = src[7 * srcStride];
        const int src8 = src[8 * srcStride];
        const int src9 = src[9 * srcStride];

        for (int j = 0; j < 9; j++) {
            int base_src = src[j * srcStride];
            int next_src = src[(j + 1) * srcStride];
            int prev_src = (j == 0) ? srcA : src[(j - 1) * srcStride];
            dst[j * dstStride] = (((dst[j * dstStride]) + cm[(-(prev_src + next_src) + base_src * C1 + next_src * C2 + 8) >> 4] + 1) >> 1);
        }

        dst++;
        src++;
    }
}
