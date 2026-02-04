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
    for (loop_cnt = (height >> 1); loop_cnt--;) {
        uint8_t temp0_0, temp0_1;
        int16_t temp1_0, temp1_1;

        temp0_0 = src0_ptr[0];
        temp0_1 = src0_ptr[src_stride];
        temp1_0 = src1_ptr[0];
        temp1_1 = src1_ptr[src2_stride];

        dst[0] = (uint8_t)(temp0_0 + temp1_0);
        dst[dst_stride] = (uint8_t)(temp0_1 + temp1_1);

        src0_ptr += (2 * src_stride);
        src1_ptr += (2 * src2_stride);
        dst += (2 * dst_stride);
    }
}
