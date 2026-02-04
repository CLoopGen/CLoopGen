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
        uint8_t temp0 = src0_ptr[0];
        uint8_t temp1 = src0_ptr[1];
        uint8_t temp2 = src0_ptr[2];
        uint8_t temp3 = src0_ptr[3];
        
        int16_t val1 = src1_ptr[0];
        int16_t val2 = src1_ptr[1];
        int16_t val3 = src1_ptr[2];
        int16_t val4 = src1_ptr[3];

        dst[0] = (uint8_t)(val1 + temp0);
        dst[1] = (uint8_t)(val2 + temp1);
        dst[2] = (uint8_t)(val3 + temp2);
        dst[3] = (uint8_t)(val4 + temp3);

        src0_ptr += src_stride;
        src1_ptr += src2_stride;
        dst += dst_stride;
    }
}
