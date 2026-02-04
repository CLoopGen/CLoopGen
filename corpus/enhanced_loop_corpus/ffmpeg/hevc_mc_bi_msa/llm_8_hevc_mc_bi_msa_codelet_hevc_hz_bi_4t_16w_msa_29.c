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
    for (loop_cnt = height; loop_cnt--;) {
        uint8_t val0 = src0_ptr[0];
        uint8_t val1 = src0_ptr[src_stride];
        int16_t acc0 = src1_ptr[0] + val0;
        int16_t acc1 = src1_ptr[src2_stride] + val1;

        dst[0] = (acc0 > 255) ? 255 : (acc0 < 0) ? 0 : acc0;
        dst[dst_stride] = (acc1 > 255) ? 255 : (acc1 < 0) ? 0 : acc1;

        src0_ptr += src_stride;
        src1_ptr += src2_stride;
        dst += dst_stride;
    }
}
