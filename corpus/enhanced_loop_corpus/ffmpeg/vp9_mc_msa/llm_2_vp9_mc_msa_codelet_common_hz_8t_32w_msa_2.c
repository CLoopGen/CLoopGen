#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern int32_t src_stride;
extern uint8_t *dst;
extern int32_t dst_stride;
extern int32_t height;
extern uint32_t loop_cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (loop_cnt = (height >> 1); loop_cnt--;) {
        // Variant 1: Consecutive memory access with pointer pre-increment and coalesced loads/stores
        uint8_t *src1 = src + src_stride;
        uint8_t *src2 = src + 2 * src_stride;
        uint8_t *dst1 = dst;
        uint8_t *dst2 = dst + dst_stride;

        // Simulate vectorizable body by accessing consecutive elements
        for (int i = 0; i < 8; ++i) {
            dst1[i] = src1[i];
            dst2[i] = src2[i];
        }

        src = src2;
        dst = dst2 + dst_stride;
    }
}
