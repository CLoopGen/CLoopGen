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
    // Eliminate most dependencies by working on independent temporaries
    uint8_t val0 = src0_ptr[0];
    uint8_t val1 = src0_ptr[src_stride];
    uint8_t val2 = src0_ptr[src_stride * 2];
    uint8_t val3 = src0_ptr[src_stride * 3];

    int16_t v1 = src1_ptr[0];
    int16_t v2 = src1_ptr[src2_stride];
    int16_t v3 = src1_ptr[src2_stride * 2];
    int16_t v4 = src1_ptr[src2_stride * 3];

    // Break loop-carried dependencies: make operations independent
    dst[0] = (uint8_t)(v1 + v2);
    dst[1] = (uint8_t)(v3 + v4);
    dst[dst_stride] = val0 ^ val2;
    dst[dst_stride + 1] = val1 ^ val3;

    // Update all pointers in batch — no intra-loop data dependence
    src0_ptr += src_stride * 2;
    src1_ptr += src2_stride * 2;
    dst += dst_stride * 2;

    // No use of previous values; fully pipelined friendly
}
}
