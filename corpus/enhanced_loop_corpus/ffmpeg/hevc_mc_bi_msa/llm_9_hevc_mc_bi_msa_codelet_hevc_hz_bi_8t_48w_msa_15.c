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
extern uint32_t loop_cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (loop_cnt = 32; loop_cnt--;) {
    int offset;
    for (int k = 0; k < 2; ++k) {
        offset = k * 8;
        dst[offset + 0] = (src0_ptr[0] + src0_ptr[1]) >> 1;
        dst[offset + 1] = (src0_ptr[2] + src0_ptr[3]) >> 1;
        dst[offset + 2] = (src1_ptr[0] + src1_ptr[1] + 1) >> 1;
        dst[offset + 3] = (src1_ptr[2] + src1_ptr[3] + 1) >> 1;
        dst[offset + 4] = src0_ptr[0] ^ src1_ptr[0];
        dst[offset + 5] = src0_ptr[1] ^ src1_ptr[1];
        dst[offset + 6] = src0_ptr[2] | src1_ptr[2];
        dst[offset + 7] = src0_ptr[3] & src1_ptr[3];
    }
    src0_ptr += src_stride;
    src1_ptr += src2_stride;
    dst += dst_stride;
}
}
