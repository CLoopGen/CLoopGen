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
    dst[0] = ((dst[0]) + cm[((-7 * src[-1] + 42 * src[0] + 96 * src[1] + -2 * src[2] + -1 * src[3]) + 64) >> 7] + 1) >> 1;
    dst[1] = ((dst[1]) + cm[((-7 * src[0] + 42 * src[1] + 96 * src[2] + -2 * src[3] + -1 * src[4]) + 64) >> 7] + 1) >> 1;
    dst[2] = ((dst[2]) + cm[((-7 * src[1] + 42 * src[2] + 96 * src[3] + -2 * src[4] + -1 * src[5]) + 64) >> 7] + 1) >> 1;
    dst[3] = ((dst[3]) + cm[((-7 * src[2] + 42 * src[3] + 96 * src[4] + -2 * src[5] + -1 * src[6]) + 64) >> 7] + 1) >> 1;

    if (i + 1 < h) {
        uint8_t *dst_next = dst + dstStride;
        uint8_t *src_next = src + srcStride;

        dst_next[4] = ((dst_next[4]) + cm[((-7 * src_next[1] + 42 * src_next[2] + 96 * src_next[3] + -2 * src_next[4] + -1 * src_next[5]) + 64) >> 7] + 1) >> 1;
        dst_next[5] = ((dst_next[5]) + cm[((-7 * src_next[2] + 42 * src_next[3] + 96 * src_next[4] + -2 * src_next[5] + -1 * src_next[6]) + 64) >> 7] + 1) >> 1;
        dst_next[6] = ((dst_next[6]) + cm[((-7 * src_next[3] + 42 * src_next[4] + 96 * src_next[5] + -2 * src_next[6] + -1 * src_next[7]) + 64) >> 7] + 1) >> 1;
        dst_next[7] = ((dst_next[7]) + cm[((-7 * src_next[4] + 42 * src_next[5] + 96 * src_next[6] + -2 * src_next[7] + -1 * src_next[8]) + 64) >> 7] + 1) >> 1;
    }

    dst += 2 * dstStride;
    src += 2 * srcStride;
}
}
