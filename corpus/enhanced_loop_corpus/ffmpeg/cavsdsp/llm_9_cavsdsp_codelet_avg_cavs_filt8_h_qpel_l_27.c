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
    // Unroll loop: process two rows per iteration
    if (i + 0 < h) {
        dst[0] = ((dst[0]) + cm[((-1 * src[-2] - 2 * src[-1] + 96 * src[0] + 42 * src[1] - 7 * src[2]) + 64) >> 7] + 1) >> 1;
        dst[1] = ((dst[1]) + cm[((-1 * src[-1] - 2 * src[0] + 96 * src[1] + 42 * src[2] - 7 * src[3]) + 64) >> 7] + 1) >> 1;
        dst[2] = ((dst[2]) + cm[((-1 * src[0] - 2 * src[1] + 96 * src[2] + 42 * src[3] - 7 * src[4]) + 64) >> 7] + 1) >> 1;
        dst[3] = ((dst[3]) + cm[((-1 * src[1] - 2 * src[2] + 96 * src[3] + 42 * src[4] - 7 * src[5]) + 64) >> 7] + 1) >> 1;
        dst[4] = ((dst[4]) + cm[((-1 * src[2] - 2 * src[3] + 96 * src[4] + 42 * src[5] - 7 * src[6]) + 64) >> 7] + 1) >> 1;
        dst[5] = ((dst[5]) + cm[((-1 * src[3] - 2 * src[4] + 96 * src[5] + 42 * src[6] - 7 * src[7]) + 64) >> 7] + 1) >> 1;
        dst[6] = ((dst[6]) + cm[((-1 * src[4] - 2 * src[5] + 96 * src[6] + 42 * src[7] - 7 * src[8]) + 64) >> 7] + 1) >> 1;
        dst[7] = ((dst[7]) + cm[((-1 * src[5] - 2 * src[6] + 96 * src[7] + 42 * src[8] - 7 * src[9]) + 64) >> 7] + 1) >> 1;

        uint8_t* next_dst = dst + dstStride;
        uint8_t* next_src = src + srcStride;

        next_dst[0] = ((next_dst[0]) + cm[((-1 * next_src[-2] - 2 * next_src[-1] + 96 * next_src[0] + 42 * next_src[1] - 7 * next_src[2]) + 64) >> 7] + 1) >> 1;
        next_dst[1] = ((next_dst[1]) + cm[((-1 * next_src[-1] - 2 * next_src[0] + 96 * next_src[1] + 42 * next_src[2] - 7 * next_src[3]) + 64) >> 7] + 1) >> 1;
        next_dst[2] = ((next_dst[2]) + cm[((-1 * next_src[0] - 2 * next_src[1] + 96 * next_src[2] + 42 * next_src[3] - 7 * next_src[4]) + 64) >> 7] + 1) >> 1;
        next_dst[3] = ((next_dst[3]) + cm[((-1 * next_src[1] - 2 * next_src[2] + 96 * next_src[3] + 42 * next_src[4] - 7 * next_src[5]) + 64) >> 7] + 1) >> 1;
        next_dst[4] = ((next_dst[4]) + cm[((-1 * next_src[2] - 2 * next_src[3] + 96 * next_src[4] + 42 * next_src[5] - 7 * next_src[6]) + 64) >> 7] + 1) >> 1;
        next_dst[5] = ((next_dst[5]) + cm[((-1 * next_src[3] - 2 * next_src[4] + 96 * next_src[5] + 42 * next_src[6] - 7 * next_src[7]) + 64) >> 7] + 1) >> 1;
        next_dst[6] = ((next_dst[6]) + cm[((-1 * next_src[4] - 2 * next_src[5] + 96 * next_src[6] + 42 * next_src[7] - 7 * next_src[8]) + 64) >> 7] + 1) >> 1;
        next_dst[7] = ((next_dst[7]) + cm[((-1 * next_src[5] - 2 * next_src[6] + 96 * next_src[7] + 42 * next_src[8] - 7 * next_src[9]) + 64) >> 7] + 1) >> 1;
    }

    dst += 2 * dstStride;
    src += 2 * srcStride;
}
}
