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
    for (loop_cnt = 32; loop_cnt--;) {
        uint8_t temp0 = src0_ptr[0];
        uint8_t temp1 = src0_ptr[1];
        int16_t temp2 = src1_ptr[0] + 10;
        int16_t temp3 = src1_ptr[1] + 20;

        dst[0] = (uint8_t)((temp0 + temp1) / 2);
        dst[1] = (uint8_t)(temp2 & 0xFF);
        dst[2] = (uint8_t)(temp3 & 0xFF);

        src0_ptr += src_stride;
        src1_ptr += src2_stride;
        dst += dst_stride;
    }
}
