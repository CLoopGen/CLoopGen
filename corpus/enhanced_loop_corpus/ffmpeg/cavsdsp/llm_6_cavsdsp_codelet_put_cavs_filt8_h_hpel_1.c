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
for (i = 0; i < h; i++) {
    int offset = 4;
    uint8_t s0 = src[-2], s1 = src[-1], s2 = src[0], s3 = src[1], s4 = src[2], s5 = src[3];
    uint8_t s6 = src[4], s7 = src[5], s8 = src[6], s9 = src[7], s10 = src[8], s11 = src[9], s12 = src[10];

    dst[0] = cm[((0 * s0 + -1 * s1 + 5 * s2 + 5 * s3 + -1 * s4 + 0 * s5) + offset) >> 3];
    dst[1] = cm[((0 * s1 + -1 * s2 + 5 * s3 + 5 * s4 + -1 * s5 + 0 * s6) + offset) >> 3];
    dst[2] = cm[((0 * s2 + -1 * s3 + 5 * s4 + 5 * s5 + -1 * s6 + 0 * s7) + offset) >> 3];
    dst[3] = cm[((0 * s3 + -1 * s4 + 5 * s5 + 5 * s6 + -1 * s7 + 0 * s8) + offset) >> 3];
    dst[4] = cm[((0 * s4 + -1 * s5 + 5 * s6 + 5 * s7 + -1 * s8 + 0 * s9) + offset) >> 3];
    dst[5] = cm[((0 * s5 + -1 * s6 + 5 * s7 + 5 * s8 + -1 * s9 + 0 * s10) + offset) >> 3];
    dst[6] = cm[((0 * s6 + -1 * s7 + 5 * s8 + 5 * s9 + -1 * s10 + 0 * s11) + offset) >> 3];
    dst[7] = cm[((0 * s7 + -1 * s8 + 5 * s9 + 5 * s10 + -1 * s11 + 0 * s12) + offset) >> 3];

    dst += dstStride;
    src += srcStride;
}
}
