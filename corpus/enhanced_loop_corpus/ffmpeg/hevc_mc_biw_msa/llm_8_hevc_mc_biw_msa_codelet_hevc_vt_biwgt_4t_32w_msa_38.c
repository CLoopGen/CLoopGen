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
extern uint8_t *dst_tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (loop_cnt = (height >> 2); loop_cnt--;) {
        uint32_t inner;
        for (inner = 0; inner < 4; inner++) {
            dst[0] = src0_ptr[0];
            dst[1] = src0_ptr[1];
            ((uint16_t*)dst_tmp)[0] = (uint16_t)(src1_ptr[0] + 1);
            ((uint16_t*)dst_tmp)[1] = (uint16_t)(src1_ptr[1] + 1);

            dst += dst_stride;
            dst_tmp += dst_stride;
            src0_ptr += src_stride;
            src1_ptr += src2_stride;
        }
        dst += dst_stride; 
        dst_tmp += dst_stride;
        src0_ptr += src_stride;
        src1_ptr += src2_stride;
    }
}
