#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern ptrdiff_t dst_stride;
extern uint8_t *src;
extern ptrdiff_t src_stride;
extern int height;
extern uint32_t loop_cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
uint8_t *s0, *s1, *s2, *s3;
uint8_t *d0, *d1, *d2, *d3;

for (loop_cnt = (height >> 2); loop_cnt--;) {
    s0 = src;
    s1 = src + src_stride;
    s2 = src + 2*src_stride;
    s3 = src + 3*src_stride;

    d0 = dst;
    d1 = dst + dst_stride;
    d2 = dst + 2*dst_stride;
    d3 = dst + 3*dst_stride;

    d0[0] = s0[0];
    d1[0] = s1[0];
    d2[0] = s2[0];
    d3[0] = s3[0];

    d0[1] = s0[1];
    d1[1] = s1[1];
    d2[1] = s2[1];
    d3[1] = s3[1];

    src += (4 * src_stride);
    dst += (4 * dst_stride);
}
}
