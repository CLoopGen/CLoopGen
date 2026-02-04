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
    uint32_t half_height = height >> 1;
    for (loop_cnt = half_height; loop_cnt--;) {
        dst[0] = *src0_ptr + (uint8_t)((src1_ptr[0] >> 2) & 0x3F);
        dst[1] = src0_ptr[1] + (uint8_t)((src1_ptr[1] >> 2) & 0x3F);

        src0_ptr += src_stride << 1;
        src1_ptr += src2_stride << 1;
        dst += dst_stride << 1;
    }
    if (height & 1) {
        dst[0] = *src0_ptr;
        dst += dst_stride;
    }
}
