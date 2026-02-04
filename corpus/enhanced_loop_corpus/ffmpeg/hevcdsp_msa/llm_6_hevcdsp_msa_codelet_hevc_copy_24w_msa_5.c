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
    int32_t offset0 = 0 * src_stride;
    int32_t offset1 = 1 * src_stride;
    int32_t offset2 = 2 * src_stride;
    int32_t offset3 = 3 * src_stride;

    uint8_t s0 = src[offset0];
    uint8_t s1 = src[offset1];
    uint8_t s2 = src[offset2];
    uint8_t s3 = src[offset3];

    int16_t d0 = (int16_t)s0 + 10;
    int16_t d1 = (int16_t)s1 + 10;
    int16_t d2 = (int16_t)s2 + 10;
    int16_t d3 = (int16_t)s3 + 10;

    dst[0 * dst_stride] = d0;
    dst[1 * dst_stride] = d1;
    dst[2 * dst_stride] = d2;
    dst[3 * dst_stride] = d3;

    src += (4 * src_stride);
    dst += (4 * dst_stride);
}
}
