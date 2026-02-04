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
        uint8_t temp0 = src0_ptr[0];
        uint8_t temp1 = src0_ptr[src_stride];
        src0_ptr += src_stride;
        src0_ptr += src_stride;

        int16_t temp2 = src1_ptr[0];
        int16_t temp3 = src1_ptr[src2_stride / sizeof(int16_t)];
        src1_ptr += src2_stride;
        src1_ptr += src2_stride;

        uint8_t combined = (temp0 + temp1) % 256;
        int16_t scaled = (temp2 + temp3) * 2;

        dst[0] = combined;
        dst[dst_stride] = (scaled >> 8) & 0xFF;

        dst += (2 * dst_stride);
    }
}
