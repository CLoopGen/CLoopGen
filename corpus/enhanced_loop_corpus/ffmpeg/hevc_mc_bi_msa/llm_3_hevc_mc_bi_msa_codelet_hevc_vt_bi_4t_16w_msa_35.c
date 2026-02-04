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
extern int32_t loop_cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (loop_cnt = (height >> 2); loop_cnt--;) {
    // Variant 2: Strided memory access with increased stride factor (every 4th element)
    // Access elements with a fixed internal stride (e.g., every 4th byte) to simulate filter or subsampling pattern

    const int step = 4; // Stride within the row: process every 4th element

    for (int row = 0; row < 4; row += 2) {
        uint8_t *src0_base = src0_ptr + row * src_stride;
        int16_t *src1_base = src1_ptr + row * src2_stride;
        uint8_t *dst_base = dst + row * dst_stride;

        for (int col = 0; col < step * 4; col += step) {
            // Ensure we don't go out of bounds (assume sufficient padding)
            int32_t val0 = src0_base[col];
            int32_t val1 = src1_base[col];
            int32_t result = val0 + (val1 >> 1); // Example operation: blend with downscale
            dst_base[col] = (result > 255) ? 255 : ((result < 0) ? 0 : (uint8_t)result);
        }
    }

    // Update outer pointers by 4 rows as per original loop semantics
    src0_ptr += 4 * src_stride;
    src1_ptr += 4 * src2_stride;
    dst += 4 * dst_stride;
}
}
