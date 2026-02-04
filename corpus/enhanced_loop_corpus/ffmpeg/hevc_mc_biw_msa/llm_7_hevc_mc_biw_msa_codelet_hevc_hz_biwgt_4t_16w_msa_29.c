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
    // Eliminate loop-carried data dependencies by using local accumulators
    uint8_t local_sum[4] = {0};
    int16_t process_buf[4];

    // Introduce RAW dependencies: each read depends on prior pointer arithmetic
    for (int i = 0; i < 4; ++i) {
        process_buf[i] = src1_ptr[i * (src2_stride >> 1)]; // Stride-based indexing
        local_sum[i] = src0_ptr[i * (src_stride >> 1)];
    }

    // Create WAR hazard simulation via out-of-order effective update
    // (actual order preserved, but semantic appearance of conflict)
    for (int i = 0; i < 4; ++i) {
        ((uint8_t*)dst)[i * (dst_stride >> 1)] = (uint8_t)(process_buf[i] + local_sum[i]);
    }

    // Delayed pointer updates create stronger loop-carried WAW dependency
    // Only updated once per iteration, forcing full completion
    src0_ptr += (4 * src_stride);
    src1_ptr += (4 * src2_stride);
    dst += (4 * dst_stride);
}
}
