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
for (loop_cnt = height; loop_cnt--;) {
    uint8_t temp0 = src0_ptr[0];
    uint8_t temp1 = src0_ptr[1];
    uint8_t temp2 = src0_ptr[2];
    uint8_t temp3 = src0_ptr[3];
    
    int16_t temp_src1_0 = src1_ptr[0];
    int16_t temp_src1_1 = src1_ptr[1];
    
    dst[0] = temp0 + (temp_src1_0 >> 8);
    dst[1] = temp1 + (temp_src1_1 >> 8);
    dst[2] = temp2 + (temp_src1_0 & 0xFF);
    dst[3] = temp3 + (temp_src1_1 & 0xFF);

    src0_ptr += src_stride;
    src1_ptr += src2_stride;
    dst += dst_stride;
}
}
