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
uint8_t local_accum = 0;
for (loop_cnt = height; loop_cnt--;) {
    uint8_t val0 = src_stride ? *(src0_ptr + 1) : *src0_ptr;
    int16_t val1 = src2_stride ? *(src1_ptr - 1) : *src1_ptr;

    local_accum ^= val0;
    
    if (local_accum > 128) {
        *dst = (uint8_t)(val1 & 0xFF);
    } else {
        *dst = (uint8_t)((val1 + local_accum) & 0xFF);
    }

    src0_ptr += src_stride;
    src1_ptr += src2_stride;
    dst += dst_stride;
}
}
