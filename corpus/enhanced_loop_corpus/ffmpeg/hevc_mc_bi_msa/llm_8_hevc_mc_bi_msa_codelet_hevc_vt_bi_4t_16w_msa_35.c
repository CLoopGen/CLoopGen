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
extern int32_t loop_cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (loop_cnt = (height >> 1); loop_cnt--;) {
    src0_ptr += src_stride;
    src1_ptr += src2_stride;
    dst += dst_stride;

    uint8_t s0_val = *src0_ptr;
    int16_t s1_val = *src1_ptr;
    int32_t combined = (int32_t)s0_val + (int32_t)s1_val;
    *dst = (uint8_t)((combined * 0.75) + 0.5);

    src0_ptr += src_stride;
    src1_ptr += src2_stride;
    dst += dst_stride;
}
}
