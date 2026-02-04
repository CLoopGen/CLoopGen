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
        src0_ptr += src_stride;
        src1_ptr += src2_stride;
        dst += dst_stride;

        {
            uint8_t s0_0 = src0_ptr[0];
            uint8_t s0_1 = src0_ptr[1];
            int16_t s1_0 = src1_ptr[0];
            int16_t s1_1 = src1_ptr[1];

            int32_t sum0 = (int32_t)s0_0 + (int32_t)s1_0;
            int32_t sum1 = (int32_t)s0_1 + (int32_t)s1_1;

            dst[0] = (uint8_t)((sum0 > 255) ? 255 : (sum0 < 0 ? 0 : sum0));
            dst[1] = (uint8_t)((sum1 > 255) ? 255 : (sum1 < 0 ? 0 : sum1));
        }

        src0_ptr += src_stride;
        src1_ptr += src2_stride;
        dst += dst_stride;
    }
}
