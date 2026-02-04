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
        // Variant 2: Strided memory access with transposed traversal
        // Instead of processing rows sequentially, access every other row first, then fill in
        // This creates a non-consecutive access pattern to simulate cache stress or tiling preparation

        // Access in two passes: even/odd row groups with larger strides
        for (int pass = 0; pass < 2; ++pass) {
            uint8_t *s0 = src0_ptr + pass * 2 * src_stride;
            int16_t *s1 = src1_ptr + pass * 2 * src2_stride;
            uint8_t *d = dst + pass * 2 * dst_stride;

            // Within each pass, process two rows with unit stride
            for (int row = 0; row < 2; ++row) {
                // Dummy vector-like access: load multiple elements per row
                for (int col = 0; col < 4; ++col) {
                    (void)s0[col];
                    (void)s1[col];
                    (void)d[col];
                }
                s0 += src_stride;
                s1 += src2_stride;
                d += dst_stride;
            }
        }

        // Advance main pointers by full block height
        src0_ptr += (4 * src_stride);
        src1_ptr += (4 * src2_stride);
        dst += (4 * dst_stride);
    }
}
