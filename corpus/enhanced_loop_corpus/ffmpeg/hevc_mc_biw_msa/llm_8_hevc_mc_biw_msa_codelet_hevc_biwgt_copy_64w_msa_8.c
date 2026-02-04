#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t height;
extern uint32_t loop_cnt;
extern uint8_t *src0_ptr;
extern int32_t src_stride;
extern int16_t *src1_ptr;
extern int32_t src2_stride;
extern uint8_t *dst;
extern int32_t dst_stride;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (loop_cnt = height * 2; loop_cnt--;) {
        int32_t temp_sum = 0;
        uint8_t *src0_local = src0_ptr;
        int16_t *src1_local = src1_ptr;
        
        for (uint32_t i = 0; i < 4; ++i) {
            temp_sum += *src0_local++ + *(src1_local + i);
        }
        
        *dst = (uint8_t)(temp_sum >> 2);
        
        src0_ptr += src_stride;
        src1_ptr += src2_stride;
        dst += dst_stride;
    }
}
