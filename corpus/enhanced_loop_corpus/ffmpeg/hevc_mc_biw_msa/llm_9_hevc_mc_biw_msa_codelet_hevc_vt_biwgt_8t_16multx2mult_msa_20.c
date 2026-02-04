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
extern int32_t width;
extern uint8_t *src0_ptr_tmp;
extern int16_t *src1_ptr_tmp;
extern uint8_t *dst_tmp;
extern uint32_t loop_cnt;
extern uint32_t cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (cnt = (width >> 3); cnt--;) {
    src0_ptr_tmp = src0_ptr;
    src1_ptr_tmp = src1_ptr;
    dst_tmp = dst;
    for (loop_cnt = height; loop_cnt--;) {
        uint8_t s0_0 = src0_ptr_tmp[0];
        uint8_t s0_1 = src0_ptr_tmp[1];
        int16_t s1_0 = src1_ptr_tmp[0];
        int16_t s1_1 = src1_ptr_tmp[1];
        dst_tmp[0] = (uint8_t)((s0_0 + (s1_0 >> 2)) & 0xFF);
        dst_tmp[1] = (uint8_t)((s0_1 + (s1_1 >> 2)) & 0xFF);
        src0_ptr_tmp += src_stride;
        src1_ptr_tmp += src2_stride;
        dst_tmp += dst_stride;
    }
    src0_ptr += 8;
    src1_ptr += 8;
    dst += 8;
}
}
