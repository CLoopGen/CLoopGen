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
extern uint32_t loop_cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (loop_cnt = 64; loop_cnt--;) {
    uint8_t temp0 = src0_ptr[0];
    uint8_t temp1 = src0_ptr[1];
    uint8_t temp2 = src0_ptr[2];
    uint8_t temp3 = src0_ptr[3];
    uint8_t temp4 = src0_ptr[4];
    uint8_t temp5 = src0_ptr[5];
    uint8_t temp6 = src0_ptr[6];
    uint8_t temp7 = src0_ptr[7];

    int16_t temp8 = src1_ptr[0];
    int16_t temp9 = src1_ptr[1];
    int16_t temp10 = src1_ptr[2];
    int16_t temp11 = src1_ptr[3];
    int16_t temp12 = src1_ptr[4];
    int16_t temp13 = src1_ptr[5];
    int16_t temp14 = src1_ptr[6];
    int16_t temp15 = src1_ptr[7];

    dst[0] = temp0;
    dst[1] = temp1;
    dst[2] = temp2;
    dst[3] = temp3;
    dst[4] = temp4;
    dst[5] = temp5;
    dst[6] = temp6;
    dst[7] = temp7;

    ((int16_t*)dst)[8] = temp8;
    ((int16_t*)dst)[9] = temp9;
    ((int16_t*)dst)[10] = temp10;
    ((int16_t*)dst)[11] = temp11;
    ((int16_t*)dst)[12] = temp12;
    ((int16_t*)dst)[13] = temp13;
    ((int16_t*)dst)[14] = temp14;
    ((int16_t*)dst)[15] = temp15;

    src0_ptr += src_stride;
    src1_ptr += src2_stride;
    dst += dst_stride;
}
}
