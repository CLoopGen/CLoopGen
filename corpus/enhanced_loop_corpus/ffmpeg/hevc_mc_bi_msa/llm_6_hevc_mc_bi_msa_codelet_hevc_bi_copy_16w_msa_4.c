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
    uint8_t temp0 = src0_ptr[0];
    uint8_t temp1 = src0_ptr[src_stride];
    uint8_t temp2 = src0_ptr[2 * src_stride];
    uint8_t temp3 = src0_ptr[3 * src_stride];

    int16_t val0 = src1_ptr[0] + temp0;
    int16_t val1 = src1_ptr[src2_stride] + temp1;
    int16_t val2 = src1_ptr[2 * src2_stride] + temp2;
    int16_t val3 = src1_ptr[3 * src2_stride] + temp3;

    dst[0] = (uint8_t)(val0 > 255 ? 255 : val0);
    dst[dst_stride] = (uint8_t)(val1 > 255 ? 255 : val1);
    dst[2 * dst_stride] = (uint8_t)(val2 > 255 ? 255 : val2);
    dst[3 * dst_stride] = (uint8_t)(val3 > 255 ? 255 : val3);

    src0_ptr += (4 * src_stride);
    src1_ptr += (4 * src2_stride);
    dst += (4 * dst_stride);
}
}
