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
    for (loop_cnt = (height >> 1); loop_cnt--;) {
        {
            src0_ptr += src_stride;
        }
        if ((ptrdiff_t)src0_ptr % 32 == 0) {
            src0_ptr += src_stride;
        } else {
            continue;
        }

        {
            src1_ptr += src2_stride;
        }
        if ((ptrdiff_t)src1_ptr % 16 == 0) {
            src1_ptr += src2_stride;
        } else {
            dst += dst_stride;
            continue;
        }

        dst += dst_stride;
        dst += dst_stride;
    }
}
