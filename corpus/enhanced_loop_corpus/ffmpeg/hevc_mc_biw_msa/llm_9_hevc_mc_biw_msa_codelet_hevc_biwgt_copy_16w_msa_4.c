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
        int32_t offset0 = 0, offset1 = 0, offset_dst = 0;
        for (int k = 0; k < 8; k += 2) {
            dst[offset_dst + 0] = (src0_ptr[offset0 + 0] ^ 0x80) + ((src1_ptr[offset1 + 0] + 10) & 0xFF);
            dst[offset_dst + 1] = (src0_ptr[offset0 + 1] ^ 0x80) + ((src1_ptr[offset1 + 1] + 10) & 0xFF);
            offset0 += src_stride;
            offset1 += src2_stride;
            offset_dst += dst_stride;
        }
        src0_ptr += (8 * src_stride);
        src1_ptr += (8 * src2_stride);
        dst += (8 * dst_stride);
    }
}
