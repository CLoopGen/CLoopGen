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
    uint8_t val0_1 = src0_ptr[0];
    uint8_t val0_2 = src0_ptr[1];
    int16_t val1_1 = src1_ptr[0];
    int16_t val2_1 = src1_ptr[1];

    int32_t sum1 = val0_1 + val1_1;
    int32_t sum2 = val0_2 + val2_1;
    int32_t prod1 = sum1 * 3;
    int32_t prod2 = sum2 * 5;

    dst[0] = (uint8_t)((prod1 >> 2) & 0xFF);
    dst[1] = (uint8_t)((prod2 >> 2) & 0xFF);

    src0_ptr += src_stride;
    src1_ptr += src2_stride;
    dst += dst_stride;
}
}
