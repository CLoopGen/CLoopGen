#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern int32_t src_stride;
extern uint8_t *dst;
extern int32_t dst_stride;
extern int32_t height;
extern uint32_t loop_cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (loop_cnt = height >> 2; loop_cnt--;) {
    uint8_t temp1, temp2, temp3, temp4;
    uint8_t *s0 = src;
    uint8_t *s1 = src + src_stride;
    uint8_t *s2 = src + 2*src_stride;
    uint8_t *s3 = src + 3*src_stride;
    uint8_t *d0 = dst;
    uint8_t *d1 = dst + dst_stride;
    uint8_t *d2 = dst + 2*dst_stride;
    uint8_t *d3 = dst + 3*dst_stride;

    temp1 = s0[0]; temp2 = s1[0]; temp3 = s2[0]; temp4 = s3[0];
    d0[0] = temp1;
    d1[0] = temp2;
    d2[0] = temp3;
    d3[0] = temp4;

    temp1 = s0[1]; temp2 = s1[1]; temp3 = s2[1]; temp4 = s3[1];
    d0[1] = temp1;
    d1[1] = temp2;
    d2[1] = temp3;
    d3[1] = temp4;

    temp1 = s0[2]; temp2 = s1[2]; temp3 = s2[2]; temp4 = s3[2];
    d0[2] = temp1;
    d1[2] = temp2;
    d2[2] = temp3;
    d3[2] = temp4;

    temp1 = s0[3]; temp2 = s1[3]; temp3 = s2[3]; temp4 = s3[3];
    d0[3] = temp1;
    d1[3] = temp2;
    d2[3] = temp3;
    d3[3] = temp4;

    src += (4 * src_stride);
    dst += (4 * dst_stride);
}
}
