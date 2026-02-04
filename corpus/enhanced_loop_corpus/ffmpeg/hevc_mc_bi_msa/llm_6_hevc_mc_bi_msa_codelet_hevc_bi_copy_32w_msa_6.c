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
    uint8_t temp_src0_0 = src0_ptr[0];
    uint8_t temp_src0_1 = src0_ptr[src_stride];
    int16_t temp_src1_0 = src1_ptr[0];
    int16_t temp_src1_1 = src1_ptr[src2_stride];

    // Introduce artificial dependency: use prior iteration's dst value (WAW & loop-carried RAW)
    static uint8_t prev_accum = 0;
    uint8_t current_accum = temp_src0_0 + temp_src0_1 + prev_accum;

    dst[0] = current_accum;
    dst[dst_stride] = current_accum ^ 0xFF;

    // Update pointers with stride
    src0_ptr += src_stride * 2;
    src1_ptr += src2_stride * 2;
    dst += dst_stride * 2;

    // Carry forward for next iteration (loop-carried dependency)
    prev_accum = current_accum;
}
}
