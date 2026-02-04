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
        int32_t offset0 = 0;
        int32_t offset1 = 0;
        int32_t offset_dst = 0;

        for (int i = 0; i < 4; i++) {
            uint8_t s0_0 = src0_ptr[offset0 + 0];
            uint8_t s0_1 = src0_ptr[offset0 + 1];
            int16_t s1_0 = src1_ptr[offset1 + 0];
            int16_t s1_1 = src1_ptr[offset1 + 1];

            int32_t sum0 = (int32_t)s0_0 + s1_0;
            int32_t sum1 = (int32_t)s0_1 + s1_1;

            dst[offset_dst + 0] = (uint8_t)(sum0 & 0xFF);
            dst[offset_dst + 1] = (uint8_t)(sum1 & 0xFF);

            dst_tmp[offset_dst + 0] = (uint8_t)((sum0 >> 4) & 0xFF);
            dst_tmp[offset_dst + 1] = (uint8_t)((sum1 >> 4) & 0xFF);

            offset0 += src_stride;
            offset1 += src2_stride;
            offset_dst += dst_stride;
        }

        src0_ptr += 4 * src_stride;
        src1_ptr += 4 * src2_stride;
        dst += 4 * dst_stride;
        dst_tmp += 4 * dst_stride;
    }
}
