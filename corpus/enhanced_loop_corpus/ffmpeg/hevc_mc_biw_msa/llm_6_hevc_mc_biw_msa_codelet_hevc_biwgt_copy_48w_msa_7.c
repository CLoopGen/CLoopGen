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
for (loop_cnt = 64; loop_cnt--;) {
    uint8_t temp_load = *src0_ptr;
    int16_t temp_load2 = *src1_ptr;
    *dst = (uint8_t)(temp_load + temp_load2);
    src0_ptr += src_stride;
    src1_ptr += src2_stride;
    dst += dst_stride;
}
}
