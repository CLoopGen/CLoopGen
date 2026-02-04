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
    uint8_t temp0_0, temp0_1, temp0_2, temp0_3;
    uint8_t temp1_0, temp1_1, temp1_2, temp1_3;
    int16_t accum0 = 0, accum1 = 0;

    temp0_0 = src0_ptr[0];
    temp0_1 = src0_ptr[src_stride];
    temp0_2 = src0_ptr[2 * src_stride];
    temp0_3 = src0_ptr[3 * src_stride];

    temp1_0 = src1_ptr[0];
    temp1_1 = src1_ptr[src2_stride];
    temp1_2 = src1_ptr[2 * src2_stride];
    temp1_3 = src1_ptr[3 * src2_stride];

    accum0 += temp0_0 + temp1_0;
    accum0 += temp0_1 + temp1_1;
    accum1 += temp0_2 + temp1_2;
    accum1 += temp0_3 + temp1_3;

    dst[0] = (uint8_t)(accum0 >> 2);
    dst[dst_stride] = (uint8_t)(accum0 >> 2);
    dst[2 * dst_stride] = (uint8_t)(accum1 >> 2);
    dst[3 * dst_stride] = (uint8_t)(accum1 >> 2);

    src0_ptr += 4 * src_stride;
    src1_ptr += 4 * src2_stride;
    dst += 4 * dst_stride;
}
}
