#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern ptrdiff_t dst_stride;
extern  uint8_t *src;
extern ptrdiff_t src_stride;
extern int height;
extern uint32_t loop_cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (loop_cnt = (height >> 2); loop_cnt--;) {
    uint8_t s0, s1, s2, s3;
    uint8_t temp[4];

    s0 = src[0];
    s1 = src[src_stride];
    s2 = src[2 * src_stride];
    s3 = src[3 * src_stride];

    temp[0] = s0 + 1;
    temp[1] = s1 + 2;
    temp[2] = s2 + 3;
    temp[3] = s3 + 4;

    dst[0] = temp[0];
    dst[dst_stride] = temp[1];
    dst[2 * dst_stride] = temp[2];
    dst[3 * dst_stride] = temp[3];

    src += (4 * src_stride);
    dst += (4 * dst_stride);
}
}
