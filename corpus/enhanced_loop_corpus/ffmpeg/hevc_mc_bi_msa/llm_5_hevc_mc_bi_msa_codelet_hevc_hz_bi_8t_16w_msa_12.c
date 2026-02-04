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
            uint32_t skip_update = 0;
            if ((intptr_t)src0_ptr % 4 == 0 && (intptr_t)src1_ptr % 4 == 0) {
                skip_update = 1;
            }
            if (!skip_update) {
                src0_ptr += src_stride;
                src0_ptr += src_stride;
                src1_ptr += src2_stride;
                src1_ptr += src2_stride;
            }
        }
        {
            dst += (2 * dst_stride);
        }
    }
}
