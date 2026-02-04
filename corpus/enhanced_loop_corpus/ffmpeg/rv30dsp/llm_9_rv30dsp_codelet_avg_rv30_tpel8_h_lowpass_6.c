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
extern  int h;
extern  uint8_t *cm;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < h; i += 2) {
    if (i + 1 < h) {
        // Process two rows per iteration to increase computational intensity
        // First row
        dst[0] = (((dst[0]) + cm[(-(src[-1] + src[2]) + src[0] * C1 + src[1] * C2 + 8) >> 4] + 1) >> 1);
        dst[1] = (((dst[1]) + cm[(-(src[0] + src[3]) + src[1] * C1 + src[2] * C2 + 8) >> 4] + 1) >> 1);
        dst[2] = (((dst[2]) + cm[(-(src[1] + src[4]) + src[2] * C1 + src[3] * C2 + 8) >> 4] + 1) >> 1);
        dst[3] = (((dst[3]) + cm[(-(src[2] + src[5]) + src[3] * C1 + src[4] * C2 + 8) >> 4] + 1) >> 1);
        dst[4] = (((dst[4]) + cm[(-(src[3] + src[6]) + src[4] * C1 + src[5] * C2 + 8) >> 4] + 1) >> 1);
        dst[5] = (((dst[5]) + cm[(-(src[4] + src[7]) + src[5] * C1 + src[6] * C2 + 8) >> 4] + 1) >> 1);
        dst[6] = (((dst[6]) + cm[(-(src[5] + src[8]) + src[6] * C1 + src[7] * C2 + 8) >> 4] + 1) >> 1);
        dst[7] = (((dst[7]) + cm[(-(src[6] + src[9]) + src[7] * C1 + src[8] * C2 + 8) >> 4] + 1) >> 1);

        // Second row
        uint8_t* dst2 = dst + dstStride;
        uint8_t* src2 = src + srcStride;
        dst2[0] = (((dst2[0]) + cm[(-(src2[-1] + src2[2]) + src2[0] * C1 + src2[1] * C2 + 8) >> 4] + 1) >> 1);
        dst2[1] = (((dst2[1]) + cm[(-(src2[0] + src2[3]) + src2[1] * C1 + src2[2] * C2 + 8) >> 4] + 1) >> 1);
        dst2[2] = (((dst2[2]) + cm[(-(src2[1] + src2[4]) + src2[2] * C1 + src2[3] * C2 + 8) >> 4] + 1) >> 1);
        dst2[3] = (((dst2[3]) + cm[(-(src2[2] + src2[5]) + src2[3] * C1 + src2[4] * C2 + 8) >> 4] + 1) >> 1);
        dst2[4] = (((dst2[4]) + cm[(-(src2[3] + src2[6]) + src2[4] * C1 + src2[5] * C2 + 8) >> 4] + 1) >> 1);
        dst2[5] = (((dst2[5]) + cm[(-(src2[4] + src2[7]) + src2[5] * C1 + src2[6] * C2 + 8) >> 4] + 1) >> 1);
        dst2[6] = (((dst2[6]) + cm[(-(src2[5] + src2[8]) + src2[6] * C1 + src2[7] * C2 + 8) >> 4] + 1) >> 1);
        dst2[7] = (((dst2[7]) + cm[(-(src2[6] + src2[9]) + src2[7] * C1 + src2[8] * C2 + 8) >> 4] + 1) >> 1);

        dst += 2 * dstStride;
        src += 2 * srcStride;
    } else {
        // Handle last row if h is odd
        dst[0] = (((dst[0]) + cm[(-(src[-1] + src[2]) + src[0] * C1 + src[1] * C2 + 8) >> 4] + 1) >> 1);
        dst[1] = (((dst[1]) + cm[(-(src[0] + src[3]) + src[1] * C1 + src[2] * C2 + 8) >> 4] + 1) >> 1);
        dst[2] = (((dst[2]) + cm[(-(src[1] + src[4]) + src[2] * C1 + src[3] * C2 + 8) >> 4] + 1) >> 1);
        dst[3] = (((dst[3]) + cm[(-(src[2] + src[5]) + src[3] * C1 + src[4] * C2 + 8) >> 4] + 1) >> 1);
        dst[4] = (((dst[4]) + cm[(-(src[3] + src[6]) + src[4] * C1 + src[5] * C2 + 8) >> 4] + 1) >> 1);
        dst[5] = (((dst[5]) + cm[(-(src[4] + src[7]) + src[5] * C1 + src[6] * C2 + 8) >> 4] + 1) >> 1);
        dst[6] = (((dst[6]) + cm[(-(src[5] + src[8]) + src[6] * C1 + src[7] * C2 + 8) >> 4] + 1) >> 1);
        dst[7] = (((dst[7]) + cm[(-(src[6] + src[9]) + src[7] * C1 + src[8] * C2 + 8) >> 4] + 1) >> 1);
        dst += dstStride;
        src += srcStride;
    }
}
}
