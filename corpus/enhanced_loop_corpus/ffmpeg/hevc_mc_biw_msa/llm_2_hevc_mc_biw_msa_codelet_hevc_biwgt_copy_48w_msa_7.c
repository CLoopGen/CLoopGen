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
for (loop_cnt = 64; loop_cnt--;) {
    dst[0] = src0_ptr[0];
    dst[1] = src0_ptr[1];
    dst[2] = src0_ptr[2];
    dst[3] = src0_ptr[3];

    for (int i = 0; i < 4; ++i) {
        ((int16_t*)dst)[i] += src1_ptr[i];
    }

    src0_ptr += src_stride;
    src1_ptr += src2_stride;
    dst += dst_stride;
}
}
