#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern int32_t src_stride;
extern int16_t *dst;
extern int32_t dst_stride;
extern int32_t height;
extern int32_t width;
extern uint32_t loop_cnt;
extern uint32_t cnt;
extern uint8_t *src_tmp;
extern int16_t *dst_tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (cnt = width >> 3; cnt--;) {
    src_tmp = src;
    dst_tmp = dst;
    uint8_t s0, s1, s2, s3, s4, s5, s6, s7;
    int16_t *d0 = dst_tmp;
    int16_t *d1 = dst_tmp + dst_stride;
    int16_t *d2 = dst_tmp + 2*dst_stride;
    int16_t *d3 = dst_tmp + 3*dst_stride;
    int16_t *d4 = dst_tmp + 4*dst_stride;
    int16_t *d5 = dst_tmp + 5*dst_stride;
    int16_t *d6 = dst_tmp + 6*dst_stride;
    int16_t *d7 = dst_tmp + 7*dst_stride;

    s0 = src_tmp[0];
    s1 = src_tmp[src_stride];
    s2 = src_tmp[2*src_stride];
    s3 = src_tmp[3*src_stride];
    s4 = src_tmp[4*src_stride];
    s5 = src_tmp[5*src_stride];
    s6 = src_tmp[6*src_stride];
    src_tmp += 7 * src_stride;
    s7 = src_tmp[src_stride];

    d0[0] = s0;
    d1[0] = s1;
    d2[0] = s2;
    d3[0] = s3;
    d4[0] = s4;
    d5[0] = s5;
    d6[0] = s6;
    d7[0] = s7;

    for (loop_cnt = height - 8; loop_cnt--;) {
        src_tmp += src_stride;
        uint8_t s_val = src_tmp[0];
        dst_tmp += dst_stride;
        dst_tmp[0] = s_val;
    }
    src += 8;
    dst += 8;
}
}
