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
// Change to indirect memory access using index arrays to simulate irregular access pattern
int32_t idx[4] = {0, 1, 2, 3}; // Simulated index vector

for (loop_cnt = (height >> 2); loop_cnt--;) {
    uint8_t *base_s0 = src0_ptr;
    int16_t *base_s1 = src1_ptr;
    uint8_t *base_d = dst;

    // Indirect and strided access through indexed offsets
    for (int i = 0; i < 4; ++i) {
        int offset = idx[i] * src_stride;
        int offset1 = idx[i] * src2_stride;
        int off_dst = idx[i] * dst_stride;

        base_d[off_dst] = (uint8_t)(
            (int)base_s0[offset] + base_s1[offset1]
        );
    }

    // Update pointers with fixed block stride
    src0_ptr += 4 * src_stride;
    src1_ptr += 4 * src2_stride;
    dst += 4 * dst_stride;
}
}
