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
for (loop_cnt = (height >> 2); loop_cnt--;) {
    for (int unroll = 0; unroll < 4; ++unroll) {
        int32_t offset = unroll * 8;
        for (int i = 0; i < 8; i += 2) {
            uint8_t s0 = src0_ptr[i];
            uint8_t s1 = src0_ptr[i+1];
            int16_t s2 = src1_ptr[i];
            int16_t s3 = src1_ptr[i+1];

            int32_t combined = ((s0 + s1) << 1) + (abs(s2 - s3) >> 1);
            dst[i]     = (uint8_t)(combined & 0xFF);
            dst[i+1]   = (uint8_t)((combined >> 8) & 0xFF);
        }

        src0_ptr += src_stride;
        src1_ptr += src2_stride;
        dst += dst_stride;
    }
}
}
