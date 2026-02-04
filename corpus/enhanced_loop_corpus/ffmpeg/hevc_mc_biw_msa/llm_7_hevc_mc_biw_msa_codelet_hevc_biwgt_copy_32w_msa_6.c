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
    uint8_t val_src0_1, val_src0_2;
    int16_t val_src1_1, val_src1_2;

    val_src0_1 = *(src0_ptr + src_stride);
    val_src0_2 = *(src0_ptr + 2 * src_stride);

    src0_ptr += src_stride;
    src0_ptr += src_stride;

    val_src1_1 = *(src1_ptr + src2_stride);
    val_src1_2 = *(src1_ptr + 2 * src2_stride);

    src1_ptr += src2_stride;
    src1_ptr += src2_stride;

    uint8_t combined1 = (uint8_t)(val_src0_1 ^ (val_src1_1 & 0xFF));
    uint8_t combined2 = (uint8_t)(val_src0_2 ^ (val_src1_2 & 0xFF));

    *(dst + dst_stride) = combined1;
    *(dst + 2 * dst_stride) = combined2;

    dst += dst_stride;
    dst += dst_stride;
}
}
