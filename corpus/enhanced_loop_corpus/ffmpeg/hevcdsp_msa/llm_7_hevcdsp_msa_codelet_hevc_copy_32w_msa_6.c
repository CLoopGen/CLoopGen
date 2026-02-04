#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern int32_t src_stride;
extern int16_t *dst;
extern int32_t dst_stride;
extern int32_t height;
extern uint32_t loop_cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (loop_cnt = (height >> 2); loop_cnt--;) {
    uint8_t s0, s1, s2, s3;
    int16_t d0, d1, d2, d3;

    s0 = src[0 * src_stride];
    s1 = src[1 * src_stride];
    s2 = src[2 * src_stride];
    s3 = src[3 * src_stride];

    d0 = (int16_t)(s0 + s1);
    d1 = (int16_t)(s1 + s2);
    d2 = (int16_t)(s2 + s3);
    d3 = (int16_t)(s3 + s0);

    dst[0] = d0; dst[dst_stride] = d1;
    dst[2*dst_stride] = d2; dst[3*dst_stride] = d3;

    d0 = (int16_t)(s0 ^ 0xFF);
    d1 = (int16_t)(s1 ^ 0xFF);
    d2 = (int16_t)(s2 ^ 0xFF);
    d3 = (int16_t)(s3 ^ 0xFF);

    dst[1] = d0; 
    dst[1 + dst_stride] = d1;
    dst[1 + 2*dst_stride] = d2;
    dst[1 + 3*dst_stride] = d3;

    d0 = (int16_t)s0 << 2;
    d1 = (int16_t)s1 << 2;
    d2 = (int16_t)s2 << 2;
    d3 = (int16_t)s3 << 2;

    dst[2] = d0;
    dst[2 + dst_stride] = d1;
    dst[2 + 2*dst_stride] = d2;
    dst[2 + 3*dst_stride] = d3;

    d0 = (int16_t)(s0 * 2);
    d1 = (int16_t)(s1 * 2);
    d2 = (int16_t)(s2 * 2);
    d3 = (int16_t)(s3 * 2);

    dst[3] = d0;
    dst[3 + dst_stride] = d1;
    dst[3 + 2*dst_stride] = d2;
    dst[3 + 3*dst_stride] = d3;

    src += 4 * src_stride;
    dst += 4;
}
}
