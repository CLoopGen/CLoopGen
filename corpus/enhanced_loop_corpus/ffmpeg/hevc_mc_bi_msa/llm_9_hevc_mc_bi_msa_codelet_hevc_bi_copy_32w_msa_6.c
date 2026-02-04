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
    int32_t offset0 = 0, offset1 = 0, offset_dst = 0;
    for (uint32_t step = 0; step < 4; ++step) {
        dst[offset_dst] = (uint8_t)(src0_ptr[offset0] * 2 + src1_ptr[offset1]);
        offset0 += src_stride >> 1;
        offset1 += src2_stride >> 1;
        offset_dst += dst_stride >> 1;
    }
    src0_ptr += src_stride << 1;
    src1_ptr += src2_stride << 1;
    dst += dst_stride << 1;
}
}
