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
    // Use indirect access via index array (simulated with stride scaling)
    int32_t idx0 = (src_stride * (height - loop_cnt)) % 256;
    int32_t idx1 = (src2_stride * (height - loop_cnt)) % 128;

    // Strided and scaled memory accesses
    uint8_t temp0 = src0_ptr[idx0];
    int16_t temp1 = src1_ptr[idx1];

    // Store result using computed offset
    dst[(idx0 / 8) % dst_stride] = (uint8_t)(temp0 ^ (temp1 & 0xFF));

    // Update pointers with original strides
    src0_ptr += src_stride;
    src1_ptr += src2_stride;
    dst += dst_stride;
}
}
