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
        // Variant 1: Consecutive memory access with pointer pre-increment and coalesced updates
        uint8_t *s0_1 = src0_ptr;
        uint8_t *s0_2 = src0_ptr + src_stride;
        int16_t *s1_1 = src1_ptr;
        int16_t *s1_2 = src1_ptr + src2_stride;
        uint8_t *d_1 = dst;
        uint8_t *d_2 = dst + dst_stride;

        // Simulate processing using consecutive data loading
        uint8_t tmp0 = s0_1[0];
        uint8_t tmp1 = s0_2[0];
        int16_t tmp2 = s1_1[0];
        int16_t tmp3 = s1_2[0];

        d_1[0] = (uint8_t)(tmp0 + tmp1);
        d_2[0] = (uint8_t)(tmp2 + tmp3);

        // Update pointers in batch after use
        src0_ptr += 2 * src_stride;
        src1_ptr += 2 * src2_stride;
        dst += 2 * dst_stride;
    }
}
