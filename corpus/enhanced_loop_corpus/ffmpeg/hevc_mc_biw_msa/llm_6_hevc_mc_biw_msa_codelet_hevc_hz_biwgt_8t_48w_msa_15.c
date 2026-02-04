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
    uint8_t temp_src0 = src0_ptr[0];
    int16_t temp_src1 = src1_ptr[0];
    uint8_t computed_val = (uint8_t)(temp_src0 + (int8_t)(temp_src1 >> 8));
    
    dst[0] = computed_val;
    
    src0_ptr += src_stride;
    src1_ptr += src2_stride;
    dst += dst_stride;
}
}
