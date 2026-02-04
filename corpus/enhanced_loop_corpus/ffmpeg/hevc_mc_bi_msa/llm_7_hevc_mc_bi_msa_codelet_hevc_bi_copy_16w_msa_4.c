#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src0_ptr;
extern int32_t src_stride;
extern int16_t *src1_ptr;
extern int32_t src2_stride;
extern uint8_t *dst;
extern int32_t dst_stride;
extern int32_t height;
extern uint32_t loop_cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (loop_cnt = (height >> 2); loop_cnt--;) {
    int32_t offset0, offset1, offset2, offset3;
    offset0 = 0;
    offset1 = src_stride;
    offset2 = 2 * src_stride;
    offset3 = 3 * src_stride;

    uint8_t s0 = src0_ptr[offset0];
    uint8_t s1 = src0_ptr[offset1];
    uint8_t s2 = src0_ptr[offset2];
    uint8_t s3 = src0_ptr[offset3];

    int16_t t0 = src1_ptr[0];
    int16_t t1 = src1_ptr[src2_stride];
    int16_t t2 = src1_ptr[2 * src2_stride];
    int16_t t3 = src1_ptr[3 * src2_stride];

    uint8_t d0 = (uint8_t)((s0 + t0) & 0xFF);
    uint8_t d1 = (uint8_t)((s1 + t1) & 0xFF);
    uint8_t d2 = (uint8_t)((s2 + t2) & 0xFF);
    uint8_t d3 = (uint8_t)((s3 + t3) & 0xFF);

    dst[0] = d0;
    dst[dst_stride] = d1;
    dst[2 * dst_stride] = d2;
    dst[3 * dst_stride] = d3;

    src0_ptr += (4 * src_stride);
    src1_ptr += (4 * src2_stride);
    dst += (4 * dst_stride);

    (void)s0; (void)s1; (void)s2; (void)s3;
    (void)t0; (void)t1; (void)t2; (void)t3;
    (void)d0; (void)d1; (void)d2; (void)d3;
}
}
