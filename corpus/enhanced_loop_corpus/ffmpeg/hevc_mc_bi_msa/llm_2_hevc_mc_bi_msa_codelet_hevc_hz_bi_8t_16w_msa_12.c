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
        // Variant 1: Consecutive memory access with prefetching and coalesced pointer updates
        uint8_t *src0_row0 = src0_ptr;
        uint8_t *src0_row1 = src0_ptr + src_stride;
        int16_t *src1_row0 = src1_ptr;
        int16_t *src1_row1 = src1_ptr + src2_stride;
        uint8_t *dst_row0 = dst;
        uint8_t *dst_row1 = dst + dst_stride;

        // Simulate vectorizable, consecutive accesses
        for (int i = 0; i < 8; i++) {
            dst_row0[i] = (uint8_t)(src1_row0[i] + src1_row0[i]);
            dst_row1[i] = (uint8_t)(src1_row1[i] + src1_row1[i]);
        }

        // Update pointers with stride jumps
        src0_ptr += 2 * src_stride;
        src1_ptr += 2 * src2_stride;
        dst += 2 * dst_stride;
    }
}
