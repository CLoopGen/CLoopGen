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
    uint32_t reversed_idx;
    uint8_t *temp_src0 = src0_ptr + (height - 1) * src_stride;
    int16_t *temp_src1 = src1_ptr + (height - 1) * src2_stride;
    uint8_t *temp_dst = dst + (height - 1) * dst_stride;

    // Reverse traversal: process rows from bottom to top (inverted access pattern)
    for (reversed_idx = height; reversed_idx > 0; --reversed_idx) {
        // Strided memory access: write data with alternating destination offsets
        // Simulate indirect-like access using conditional pointer arithmetic

        size_t effective_offset = (reversed_idx % 2) ? 0 : sizeof(uint8_t);

        // Source-to-destination copy with dynamic offset
        *(uint8_t*)(temp_dst + effective_offset) = *(uint8_t*)(temp_src0 + effective_offset);

        // Dual update on secondary source using strided int16 access
        if (reversed_idx > 1) {
            ((int16_t*)temp_dst)[1] = temp_src1[1];
        }

        // Move upwards in memory (reverse direction)
        temp_src0 -= src_stride;
        temp_src1 -= src2_stride;
        temp_dst -= dst_stride;
    }
}
