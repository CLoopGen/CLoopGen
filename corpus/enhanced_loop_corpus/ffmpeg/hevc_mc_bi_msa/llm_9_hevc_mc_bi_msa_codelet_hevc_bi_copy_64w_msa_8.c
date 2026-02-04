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
for (loop_cnt = height >> 1; loop_cnt--;) {
    int offset = 0;
    for (int unroll = 0; unroll < 2; ++unroll) {
        uint8_t val0 = src0_ptr[offset];
        int16_t val1 = src1_ptr[offset];
        int32_t product = val0 * val1;
        dst[offset] = (uint8_t)((product + 128) >> 8);
        offset += 16;
    }
    src0_ptr += src_stride;
    src1_ptr += src2_stride;
    dst += dst_stride;
}
}
