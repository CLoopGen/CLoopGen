#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  uint8_t *src;
extern ptrdiff_t dstStride;
extern ptrdiff_t srcStride;
extern  int h;
extern  uint8_t *cm;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < h; i += 2) {
    dst[0] = cm[((-7 * src[-1] + 42 * src[0] + 96 * src[1] - 2 * src[2] - src[3]) + 64) >> 7];
    dst[1] = cm[((-7 * src[0] + 42 * src[1] + 96 * src[2] - 2 * src[3] - src[4]) + 64) >> 7];
    dst[2] = cm[((-7 * src[1] + 42 * src[2] + 96 * src[3] - 2 * src[4] - src[5]) + 64) >> 7];
    dst[3] = cm[((-7 * src[2] + 42 * src[3] + 96 * src[4] - 2 * src[5] - src[6]) + 64) >> 7];
    dst[4] = cm[((-7 * src[3] + 42 * src[4] + 96 * src[5] - 2 * src[6] - src[7]) + 64) >> 7];
    dst[5] = cm[((-7 * src[4] + 42 * src[5] + 96 * src[6] - 2 * src[7] - src[8]) + 64) >> 7];
    dst[6] = cm[((-7 * src[5] + 42 * src[6] + 96 * src[7] - 2 * src[8] - src[9]) + 64) >> 7];
    dst[7] = cm[((-7 * src[6] + 42 * src[7] + 96 * src[8] - 2 * src[9] - src[10]) + 64) >> 7];

    if (i + 1 < h) {
        uint8_t *dst2 = dst + dstStride;
        uint8_t *src2 = src + srcStride;

        dst2[0] = cm[((-7 * src2[-1] + 42 * src2[0] + 96 * src2[1] - 2 * src2[2] - src2[3]) + 64) >> 7];
        dst2[1] = cm[((-7 * src2[0] + 42 * src2[1] + 96 * src2[2] - 2 * src2[3] - src2[4]) + 64) >> 7];
        dst2[2] = cm[((-7 * src2[1] + 42 * src2[2] + 96 * src2[3] - 2 * src2[4] - src2[5]) + 64) >> 7];
        dst2[3] = cm[((-7 * src2[2] + 42 * src2[3] + 96 * src2[4] - 2 * src2[5] - src2[6]) + 64) >> 7];
        dst2[4] = cm[((-7 * src2[3] + 42 * src2[4] + 96 * src2[5] - 2 * src2[6] - src2[7]) + 64) >> 7];
        dst2[5] = cm[((-7 * src2[4] + 42 * src2[5] + 96 * src2[6] - 2 * src2[7] - src2[8]) + 64) >> 7];
        dst2[6] = cm[((-7 * src2[5] + 42 * src2[6] + 96 * src2[7] - 2 * src2[8] - src2[9]) + 64) >> 7];
        dst2[7] = cm[((-7 * src2[6] + 42 * src2[7] + 96 * src2[8] - 2 * src2[9] - src2[10]) + 64) >> 7];
    }

    dst += 2 * dstStride;
    src += 2 * srcStride;
}
}
