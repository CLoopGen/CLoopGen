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
    dst[0] = cm[((-1 * src[-1] + 5 * src[0] + 5 * src[1] - src[2]) + 4) >> 3];
    dst[1] = cm[((-1 * src[0] + 5 * src[1] + 5 * src[2] - src[3]) + 4) >> 3];
    dst[2] = cm[((-1 * src[1] + 5 * src[2] + 5 * src[3] - src[4]) + 4) >> 3];
    dst[3] = cm[((-1 * src[2] + 5 * src[3] + 5 * src[4] - src[5]) + 4) >> 3];
    dst[4] = cm[((-1 * src[3] + 5 * src[4] + 5 * src[5] - src[6]) + 4) >> 3];
    dst[5] = cm[((-1 * src[4] + 5 * src[5] + 5 * src[6] - src[7]) + 4) >> 3];
    dst[6] = cm[((-1 * src[5] + 5 * src[6] + 5 * src[7] - src[8]) + 4) >> 3];
    dst[7] = cm[((-1 * src[6] + 5 * src[7] + 5 * src[8] - src[9]) + 4) >> 3];

    if (i + 1 < h) {
        uint8_t *dst2 = dst + dstStride;
        uint8_t *src2 = src + srcStride;

        dst2[0] = cm[((-1 * src2[-1] + 5 * src2[0] + 5 * src2[1] - src2[2]) + 4) >> 3];
        dst2[1] = cm[((-1 * src2[0] + 5 * src2[1] + 5 * src2[2] - src2[3]) + 4) >> 3];
        dst2[2] = cm[((-1 * src2[1] + 5 * src2[2] + 5 * src2[3] - src2[4]) + 4) >> 3];
        dst2[3] = cm[((-1 * src2[2] + 5 * src2[3] + 5 * src2[4] - src2[5]) + 4) >> 3];
        dst2[4] = cm[((-1 * src2[3] + 5 * src2[4] + 5 * src2[5] - src2[6]) + 4) >> 3];
        dst2[5] = cm[((-1 * src2[4] + 5 * src2[5] + 5 * src2[6] - src2[7]) + 4) >> 3];
        dst2[6] = cm[((-1 * src2[5] + 5 * src2[6] + 5 * src2[7] - src2[8]) + 4) >> 3];
        dst2[7] = cm[((-1 * src2[6] + 5 * src2[7] + 5 * src2[8] - src2[9]) + 4) >> 3];
    }

    dst += 2 * dstStride;
    src += 2 * srcStride;
}
}
