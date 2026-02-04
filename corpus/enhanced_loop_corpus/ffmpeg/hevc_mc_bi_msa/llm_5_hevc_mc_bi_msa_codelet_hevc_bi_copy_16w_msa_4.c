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
        int32_t offset = 0;
        if ((int64_t)src0_ptr % 16 == 0 && (int64_t)src1_ptr % 16 == 0 && (int64_t)dst % 16 == 0) {
            offset = 8;
        } else {
            offset = 4;
        }

        src0_ptr += (offset * src_stride);
        src1_ptr += (offset * src2_stride);
        dst += (offset * dst_stride);

        if (offset == 8) {
            continue;
        }
    }
}
