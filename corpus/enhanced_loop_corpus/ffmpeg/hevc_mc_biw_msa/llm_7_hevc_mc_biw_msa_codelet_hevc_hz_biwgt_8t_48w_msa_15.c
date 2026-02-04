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
uint8_t local_accum = 0;
for (loop_cnt = 64; loop_cnt--;) {
    int16_t extended_val = (int16_t)src0_ptr[0];
    local_accum ^= (uint8_t)(extended_val * (int8_t)(src1_ptr[0] & 0xFF));
    
    if (local_accum & 1) {
        dst[0] = local_accum;
    }
    
    src0_ptr += src_stride;
    src1_ptr += src2_stride;
    dst += dst_stride;
    
    local_accum += 3;
}
dst[-dst_stride] = local_accum;
}
