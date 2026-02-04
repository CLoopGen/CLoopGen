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
        uint8_t temp_val = *src0_ptr;
        int16_t src1_val = *src1_ptr;

        if (temp_val > 127) {
            temp_val = 127;
        }

        if (src1_val < 0) {
            src1_val = 0;
        }

        *dst = (uint8_t)(temp_val + (src1_val >> 3));
        src0_ptr += src_stride;
        src1_ptr += src2_stride;
        dst += dst_stride;
    }
}
