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
    uint8_t s0, s1, s2, s3;
    int16_t val0, val1, val2, val3;
    uint8_t result0, result1, result2, result3;

    s0 = src0_ptr[0];
    s1 = src0_ptr[src_stride];
    val0 = src1_ptr[0] + s0;
    val1 = src1_ptr[src2_stride] + s1;

    result0 = (val0 > 255) ? 255 : (uint8_t)val0;
    result1 = (val1 > 255) ? 255 : (uint8_t)val1;

    dst[0] = result0;
    dst[dst_stride] = result1;

    s2 = src0_ptr[2 * src_stride];
    s3 = src0_ptr[3 * src_stride];
    val2 = src1_ptr[2 * src2_stride] + s2;
    val3 = src1_ptr[3 * src2_stride] + s3;

    result2 = (val2 > 255) ? 255 : (uint8_t)val2;
    result3 = (val3 > 255) ? 255 : (uint8_t)val3;

    dst[2 * dst_stride] = result2;
    dst[3 * dst_stride] = result3;

    src0_ptr += 4 * src_stride;
    src1_ptr += 4 * src2_stride;
    dst += 4 * dst_stride;
}
}
