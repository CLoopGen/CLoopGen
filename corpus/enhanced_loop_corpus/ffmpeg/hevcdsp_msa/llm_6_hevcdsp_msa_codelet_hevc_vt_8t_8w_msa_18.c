#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern int32_t src_stride;
extern int16_t *dst;
extern int32_t dst_stride;
extern int32_t height;
extern int32_t loop_cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (loop_cnt = (height >> 2); loop_cnt--;) {
    int32_t offset1 = 0 * src_stride;
    int32_t offset2 = 1 * src_stride;
    int32_t offset3 = 2 * src_stride;
    int32_t offset4 = 3 * src_stride;

    uint8_t s0, s1, s2, s3;
    s0 = src[offset1];
    s1 = src[offset2];
    s2 = src[offset3]; 
    s3 = src[offset4];

    dst[0 * dst_stride] = (int16_t)s0;
    dst[1 * dst_stride] = (int16_t)s1;
    dst[2 * dst_stride] = (int16_t)s2;
    dst[3 * dst_stride] = (int16_t)s3;

    src += (4 * src_stride);
    dst += (4 * dst_stride);
}
}
