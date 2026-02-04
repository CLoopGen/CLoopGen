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
    uint8_t *src0_row0 = src0_ptr;
    uint8_t *src0_row1 = src0_ptr + src_stride;
    int16_t *src1_row0 = src1_ptr;
    int16_t *src1_row1 = src1_ptr + src2_stride;
    uint8_t *dst_row0 = dst;
    uint8_t *dst_row1 = dst + dst_stride;

    for (int k = 0; k < 4; k += 2) {
        dst_row0[k] = (uint8_t)(src1_row0[k] + src1_row0[k + 1]);
        dst_row1[k] = (uint8_t)(src1_row1[k] + src1_row1[k + 1]);
    }

    src0_ptr += (2 * src_stride);
    src1_ptr += (2 * src2_stride);
    dst += (2 * dst_stride);
}
}
