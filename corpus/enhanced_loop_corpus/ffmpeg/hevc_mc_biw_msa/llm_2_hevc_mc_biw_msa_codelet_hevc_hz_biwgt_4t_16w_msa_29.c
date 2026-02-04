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
        // Variant 1: Consecutive memory access with array indexing (instead of pointer arithmetic)
        // All accesses are converted to use base + index * stride pattern for clarity and locality

        int32_t src0_offset = 0;
        int32_t src1_offset = 0;
        int32_t dst_offset = 0;

        for (int i = 0; i < 4; ++i) {
            uint8_t *src0_row = &src0_ptr[src0_offset];
            int16_t *src1_row = &src1_ptr[src1_offset];
            uint8_t *dst_row = &dst[dst_offset];

            // Simulate some dummy operations using consecutive row access
            (void)src0_row[0]; (void)src0_row[1]; (void)src0_row[2]; (void)src0_row[3];
            (void)src1_row[0]; (void)src1_row[1]; (void)src1_row[2]; (void)src1_row[3];
            (void)dst_row[0];  (void)dst_row[1];  (void)dst_row[2];  (void)dst_row[3];

            src0_offset += src_stride;
            src1_offset += src2_stride;
            dst_offset += dst_stride;
        }

        // Update outer pointers after processing 4 rows
        src0_ptr += (4 * src_stride);
        src1_ptr += (4 * src2_stride);
        dst += (4 * dst_stride);
    }
}
