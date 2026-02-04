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
    for (loop_cnt = (height >> 3); loop_cnt--;) {
        for (int unroll = 0; unroll < 4; ++unroll) {
            uint8_t val0 = src0_ptr[0];
            uint8_t val1 = src0_ptr[src_stride];
            uint8_t val2 = src0_ptr[2*src_stride];
            uint8_t val3 = src0_ptr[3*src_stride];

            int16_t v0 = src1_ptr[0];
            int16_t v1 = src1_ptr[src2_stride];
            int16_t v2 = src1_ptr[2*src2_stride];
            int16_t v3 = src1_ptr[3*src2_stride];

            dst[0] = (uint8_t)((val0 + (v0 >> 2)) & 0xFF);
            dst[dst_stride] = (uint8_t)((val1 + (v1 >> 2)) & 0xFF);
            dst[2*dst_stride] = (uint8_t)((val2 + (v2 >> 2)) & 0xFF);
            dst[3*dst_stride] = (uint8_t)((val3 + (v3 >> 2)) & 0xFF);

            src0_ptr += 4 * src_stride;
            src1_ptr += 4 * src2_stride;
            dst += 4 * dst_stride;
        }
    }
}
