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
        uint8_t *s0 = src;
        uint8_t *s1 = src + src_stride;
        uint8_t *s2 = src + (2 * src_stride);
        uint8_t *s3 = src + (3 * src_stride);
        
        int16_t *d0 = dst;
        int16_t *d1 = dst + dst_stride;
        int16_t *d2 = dst + (2 * dst_stride);
        int16_t *d3 = dst + (3 * dst_stride);

        d0[0] = s0[0];
        d1[0] = s1[0];
        d2[0] = s2[0];
        d3[0] = s3[0];

        d0[1] = s0[1];
        d1[1] = s1[1];
        d2[1] = s2[1];
        d3[1] = s3[1];

        d0[2] = s0[2];
        d1[2] = s1[2];
        d2[2] = s2[2];
        d3[2] = s3[2];

        d0[3] = s0[3];
        d1[3] = s1[3];
        d2[3] = s2[3];
        d3[3] = s3[3];

        src += (4 * src_stride);
        dst += (4 * dst_stride);
    }
}
