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
    uint8_t accumulator = 0;
    uint8_t *local_dst = dst;
    const uint8_t *local_src0 = src0_ptr;
    const int16_t *local_src1 = src1_ptr;
    
    for (loop_cnt = height; loop_cnt--;) {
        accumulator ^= *local_src0;
        *local_dst = accumulator;
        
        accumulator += *(local_src1);
        
        local_src0 += src_stride;
        local_src1 += src2_stride;
        local_dst += dst_stride;
    }
    
    dst = local_dst;
    src0_ptr = (uint8_t *)local_src0;
    src1_ptr = (int16_t *)local_src1;
}
