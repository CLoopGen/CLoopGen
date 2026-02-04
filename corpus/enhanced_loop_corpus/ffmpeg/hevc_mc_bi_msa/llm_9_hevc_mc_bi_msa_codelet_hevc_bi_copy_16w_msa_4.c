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
        int32_t offset;
        for (offset = 0; offset < 8; offset += 4) {
            uint8_t temp0, temp1;
            int16_t val;

            val = src1_ptr[offset * src2_stride];
            temp0 = (uint8_t)(val >> 4);
            temp1 = (uint8_t)((val + 255) >> 8);

            dst[offset * dst_stride] = temp0 ^ src0_ptr[offset * src_stride];
            dst[offset * dst_stride + 1] = temp1 ^ src0_ptr[offset * src_stride + 1];
            dst[offset * dst_stride + 2] = temp0 + temp1;
            dst[offset * dst_stride + 3] = src0_ptr[offset * src_stride + 3];

            val = src1_ptr[(offset + 2) * src2_stride];
            temp0 = (uint8_t)(val >> 4);
            temp1 = (uint8_t)((val + 255) >> 8);

            dst[(offset + 2) * dst_stride] = temp0 ^ src0_ptr[(offset + 2) * src_stride];
            dst[(offset + 2) * dst_stride + 1] = temp1 ^ src0_ptr[(offset + 2) * src_stride + 1];
        }

        src0_ptr += (8 * src_stride);
        src1_ptr += (8 * src2_stride);
        dst += (8 * dst_stride);
    }
}
