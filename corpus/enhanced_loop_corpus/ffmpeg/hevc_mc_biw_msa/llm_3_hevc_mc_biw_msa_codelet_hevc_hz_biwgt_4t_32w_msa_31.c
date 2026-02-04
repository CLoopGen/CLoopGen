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
        // Variant 2: Strided access with reverse traversal and indirect indexing
        // Use reverse indexing with dynamic offsets to create irregular but predictable access
        ptrdiff_t idx_src0 = (height - loop_cnt - 1) * src_stride;
        ptrdiff_t idx_src1 = (height - loop_cnt - 1) * src2_stride;
        ptrdiff_t idx_dst = (height - loop_cnt - 1) * dst_stride;

        uint8_t val_src0 = *(src0_ptr + idx_src0);
        int16_t val_src1 = *(src1_ptr + idx_src1);

        // Introduce conditional data flow without branching (bit manipulation)
        uint8_t result = val_src0 ^ ((val_src1 & 0xFF) ^ val_src0); // Conditional-like mixing
        *(dst + idx_dst) = result;

        // Maintain pointer progression as original semantics (though logic is now index-based)
        if (loop_cnt == 0) {
            src0_ptr += src_stride * height;
            src1_ptr += src2_stride * height;
            dst += dst_stride * height;
        }
    }
}
