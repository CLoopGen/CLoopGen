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
        // Variant 2: Strided access with transposed-like memory traversal (every Nth element)
        const int32_t skip = 4; // Simulate strided access across rows, every 4th element
        uint8_t *s0_base = src0_ptr;
        int16_t *s1_base = src1_ptr;
        uint8_t *d_base = dst;

        // Access elements with larger stride (e.g., for cache behavior simulation)
        for (int32_t step = 0; step < 4; ++step) {
            uint8_t temp0 = s0_base[step * skip];
            uint8_t temp1 = s0_base[src_stride + step * skip];
            int16_t temp2 = s1_base[step * skip];
            int16_t temp3 = s1_base[src2_stride + step * skip];

            d_base[step * skip] = (uint8_t)(temp0 ^ temp1);
            d_base[dst_stride + step * skip] = (uint8_t)(temp2 > 0 ? temp3 & 0xFF : 0);
        }

        // Advance pointers by full row strides as before
        src0_ptr += 2 * src_stride;
        src1_ptr += 2 * src2_stride;
        dst += 2 * dst_stride;
    }
}
