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
extern uint8_t *dst_tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (loop_cnt = (height >> 1); loop_cnt--;) {
    uint8_t *src0_row0 = src0_ptr;
    uint8_t *src0_row1 = src0_ptr + src_stride;
    int16_t *src1_row0 = src1_ptr;
    int16_t *src1_row1 = src1_ptr + src2_stride;
    uint8_t *dst_row0 = dst;
    uint8_t *dst_row1 = dst + dst_stride;
    uint8_t *dst_tmp_row0 = dst_tmp;
    uint8_t *dst_tmp_row1 = dst_tmp + dst_stride;

    for (int c = 0; c < 2; ++c) {
        dst_row0[c] = src0_row0[c];
        dst_row1[c] = src0_row1[c];
        dst_tmp_row0[c] = (uint8_t)(src1_row0[c] & 0xFF);
        dst_tmp_row1[c] = (uint8_t)(src1_row1[c] & 0xFF);
    }

    src1_ptr += (2 * src2_stride);
    dst += (2 * dst_stride);
    src0_ptr += (2 * src_stride);
    dst_tmp += (2 * dst_stride);
}
}
