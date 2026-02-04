#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern int32_t src_stride;
extern uint8_t *dst;
extern int32_t dst_stride;
extern int32_t height;
extern int32_t cnt;
extern uint8_t *dst_dup;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (cnt = (height / 8); cnt--;) {
    uint8_t *s0 = src;
    uint8_t *s1 = src + src_stride;
    uint8_t *s2 = src + 2*src_stride;
    uint8_t *s3 = src + 3*src_stride;
    uint8_t *s4 = src + 4*src_stride;
    uint8_t *s5 = src + 5*src_stride;
    uint8_t *s6 = src + 6*src_stride;
    uint8_t *s7 = src + 7*src_stride;

    uint8_t d0 = s0[0] + s1[0];
    uint8_t d1 = s2[0] + s3[0];
    uint8_t d2 = s4[0] + s5[0];
    uint8_t d3 = s6[0] + s7[0];

    dst_dup[0] = d0;
    dst_dup[dst_stride] = d1;
    dst_dup[2 * dst_stride] = d2;
    dst_dup[3 * dst_stride] = d3;

    dst_dup += (4 * dst_stride);

    uint8_t d4 = s0[1] ^ d0;
    uint8_t d5 = s2[1] ^ d1;
    uint8_t d6 = s4[1] ^ d2;
    uint8_t d7 = s6[1] ^ d3;

    dst_dup[0] = d4;
    dst_dup[dst_stride] = d5;
    dst_dup[2 * dst_stride] = d6;
    dst_dup[3 * dst_stride] = d7;

    src += (8 * src_stride);
    dst_dup += (4 * dst_stride);

    dst[0] = d7;
    dst[dst_stride] = d6;
    dst[2 * dst_stride] = d5;
    dst[3 * dst_stride] = d4;

    dst += (4 * dst_stride);

    dst[0] = d0 ^ d4;
    dst[dst_stride] = d1 ^ d5;
    dst[2 * dst_stride] = d2 ^ d6;
    dst[3 * dst_stride] = d3 ^ d7;

    dst += (4 * dst_stride);
}
}
