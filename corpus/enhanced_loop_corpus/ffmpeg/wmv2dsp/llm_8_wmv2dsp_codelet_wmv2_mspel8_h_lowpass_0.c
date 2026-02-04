#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  uint8_t *src;
extern int dstStride;
extern int srcStride;
extern int h;
extern  uint8_t *cm;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < h; i++) {
    int s0 = src[0], s1 = src[1], s2 = src[2], s3 = src[3];
    int s4 = src[4], s5 = src[5], s6 = src[6], s7 = src[7];
    int s8 = src[8], s9 = src[9];

    dst[0] = cm[(9 * (s0 + s1) - (src[-1] + s2) + 8) >> 4];
    dst[1] = cm[(9 * (s1 + s2) - (s0 + s3) + 8) >> 4];
    dst[2] = cm[(9 * (s2 + s3) - (s1 + s4) + 8) >> 4];
    dst[3] = cm[(9 * (s3 + s4) - (s2 + s5) + 8) >> 4];
    dst[4] = cm[(9 * (s4 + s5) - (s3 + s6) + 8) >> 4];
    dst[5] = cm[(9 * (s5 + s6) - (s4 + s7) + 8) >> 4];
    dst[6] = cm[(9 * (s6 + s7) - (s5 + s8) + 8) >> 4];
    dst[7] = cm[(9 * (s7 + s8) - (s6 + s9) + 8) >> 4];

    dst += dstStride;
    src += srcStride;
}
}
