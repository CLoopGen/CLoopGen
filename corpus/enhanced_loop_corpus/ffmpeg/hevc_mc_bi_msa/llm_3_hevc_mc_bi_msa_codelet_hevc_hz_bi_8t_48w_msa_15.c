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
    int32_t i;

    for (i = 0; i < 8; i++) {
        int32_t idx = i * (src_stride / 4); 
        dst[i] = src0_ptr[idx];
    }

    for (i = 0; i < 8; i++) {
        int32_t idx = i * (src2_stride / 2);
        ((int16_t*)dst)[8 + i] = src1_ptr[idx];
    }

    src0_ptr += src_stride * 8;
    src1_ptr += src2_stride * 8;
    dst += dst_stride;
}
}
