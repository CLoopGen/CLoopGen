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
extern uint32_t loop_cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (loop_cnt = 128; loop_cnt--;) {
        uint8_t temp0 = *src0_ptr;
        int16_t temp1 = *src1_ptr;
        int32_t sum = temp0 + temp1;
        int32_t scaled = sum << 1;
        *dst = (uint8_t)(scaled & 0xFF);

        src0_ptr += src_stride;
        src1_ptr += src2_stride;
        dst += dst_stride;
    }
}
