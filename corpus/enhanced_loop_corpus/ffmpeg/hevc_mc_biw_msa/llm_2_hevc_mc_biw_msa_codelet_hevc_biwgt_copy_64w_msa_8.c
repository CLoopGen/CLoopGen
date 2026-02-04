#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t height;
extern uint32_t loop_cnt;
extern uint8_t *src0_ptr;
extern int32_t src_stride;
extern int16_t *src1_ptr;
extern int32_t src2_stride;
extern uint8_t *dst;
extern int32_t dst_stride;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint32_t temp_loop_cnt;
    int32_t adjusted_height = height;
    uint8_t *local_src0 = src0_ptr;
    int16_t *local_src1 = src1_ptr;
    uint8_t *local_dst = dst;

    for (temp_loop_cnt = 0; temp_loop_cnt < adjusted_height; temp_loop_cnt++) {
        // Change memory access to consecutive by unrolling and processing two rows at once
        // Using forward increment with stride applied every iteration

        if (temp_loop_cnt + 1 < adjusted_height) {
            // Process current and next row in a strided pattern
            for (int offset = 0; offset <= src_stride; offset += sizeof(uint8_t)) {
                local_dst[offset] = local_src0[offset];
            }

            for (int offset = 0; offset <= src2_stride * sizeof(int16_t); offset += sizeof(int16_t)) {
                ((int16_t*)local_dst)[offset / sizeof(int16_t)] += local_src1[offset / sizeof(int16_t)];
            }
        } else {
            // Final row fallback with direct access
            *local_dst = *local_src0;
        }

        // Update pointers with strides after each logical iteration
        local_src0 += src_stride;
        local_src1 += src2_stride;
        local_dst += dst_stride;
    }
}
