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



void loop() {
    for (loop_cnt = (height >> 2); loop_cnt--;) {
        // Variant 1: Consecutive memory access with manual stride accumulation
        // Instead of jumping by 2*stride every iteration, process 4 rows consecutively
        // using direct pointer arithmetic to improve spatial locality.

        uint8_t *s0_row0 = src0_ptr;
        uint8_t *s0_row1 = src0_ptr + src_stride;
        uint8_t *s0_row2 = src0_ptr + 2 * src_stride;
        uint8_t *s0_row3 = src0_ptr + 3 * src_stride;

        int16_t *s1_row0 = src1_ptr;
        int16_t *s1_row1 = src1_ptr + src2_stride;
        int16_t *s1_row2 = src1_ptr + 2 * src2_stride;
        int16_t *s1_row3 = src1_ptr + 3 * src2_stride;

        uint8_t *d_row0 = dst;
        uint8_t *d_row1 = dst + dst_stride;
        uint8_t *d_row2 = dst + 2 * dst_stride;
        uint8_t *d_row3 = dst + 3 * dst_stride;

        // Simulate some dummy processing (e.g., copy or transform)
        d_row0[0] = s0_row0[0];
        d_row1[0] = s0_row1[0];
        d_row2[0] = s0_row2[0];
        d_row3[0] = s0_row3[0];

        // Update pointers for next block
        src0_ptr += 4 * src_stride;
        src1_ptr += 4 * src2_stride;
        dst += 4 * dst_stride;
    }
}
