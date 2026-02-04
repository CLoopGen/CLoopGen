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
int32_t offset = 0;
for (loop_cnt = height; loop_cnt--;) {
    int32_t idx = offset * 4;
    uint8_t s0_val = src0_ptr[idx];
    uint8_t s0_val_next = src0_ptr[idx + 2];
    *dst = (s0_val ^ s0_val_next) + 1;

    *(dst + 1) = *(src0_ptr + offset);
    *(dst + 2) = *(src0_ptr + offset + 1);

    src0_ptr += src_stride;
    src1_ptr += src2_stride;
    dst += dst_stride;

    offset += 1;
}
}
