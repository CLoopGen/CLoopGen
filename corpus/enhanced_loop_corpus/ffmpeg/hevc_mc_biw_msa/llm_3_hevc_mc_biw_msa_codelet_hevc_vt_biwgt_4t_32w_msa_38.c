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
extern uint8_t *dst_tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (loop_cnt = (height >> 1); loop_cnt--;) {
        // Variant 2: Strided memory access with transposed-like pattern
        // Access every 4th element across multiple rows — simulating strided vector access

        const int stride_factor = 4;
        uint8_t *s0_base = src0_ptr;
        int16_t *s1_base = src1_ptr;
        uint8_t *d_base = dst;
        uint8_t *dt_base = dst_tmp;

        // Process data in a strided column-wise fashion
        for (int col = 0; col < stride_factor; ++col) {
            uint8_t *s0 = s0_base + col;
            uint8_t *d = d_base + col;
            uint8_t *dt = dt_base + col;
            int16_t *s1 = s1_base + col;

            for (int row = 0; row < 2; ++row) {
                // Strided access across rows: jump by full stride
                d[0] = s0[0];
                dt[0] = (s0[0] + s0[1]) >> 1; // Simple filter

                s0 += src_stride;
                d += dst_stride;
                dt += dst_stride;
                s1 += src2_stride;
            }
        }

        // Update base pointers by two rows as per original logic
        dst += (2 * dst_stride);
        dst_tmp += (2 * dst_stride);
        src0_ptr += (2 * src_stride);
        src1_ptr += (2 * src2_stride);
    }
}
