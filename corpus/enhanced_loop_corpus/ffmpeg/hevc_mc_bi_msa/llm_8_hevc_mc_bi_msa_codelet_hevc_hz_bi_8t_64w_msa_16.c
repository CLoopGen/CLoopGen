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
    uint32_t i;
    int16_t temp0, temp1, temp2, temp3;
    for (i = 0; i < 8; ++i) {
        temp0 = src1_ptr[i * 4 + 0] + 16;
        temp1 = src1_ptr[i * 4 + 1] - 8;
        temp2 = src1_ptr[i * 4 + 2] * 2;
        temp3 = src1_ptr[i * 4 + 3] / 4;

        dst[i * 4 + 0] = (uint8_t)((src0_ptr[i * 4 + 0] + temp0) & 0xFF);
        dst[i * 4 + 1] = (uint8_t)((src0_ptr[i * 4 + 1] + temp1) & 0xFF);
        dst[i * 4 + 2] = (uint8_t)((src0_ptr[i * 4 + 2] + temp2) & 0xFF);
        dst[i * 4 + 3] = (uint8_t)((src0_ptr[i * 4 + 3] + temp3) & 0xFF);
    }
    src1_ptr += src2_stride;
    src0_ptr += src_stride;
    dst += dst_stride;
}
}
