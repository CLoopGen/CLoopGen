#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern ptrdiff_t dst_stride;
extern  uint8_t *src;
extern ptrdiff_t src_stride;
extern int height;
extern uint32_t loop_cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (loop_cnt = (height >> 1); loop_cnt--;) {
        // Variant 1: Consecutive memory access with pre-computed pointers
        uint8_t *src1 = src + src_stride;
        uint8_t *src2 = src + 2 * src_stride;
        uint8_t *dst1 = dst;
        uint8_t *dst2 = dst + dst_stride;

        // Simulate processing by reading from consecutive source lines and writing to consecutive destination lines
        dst1[0] = src1[0];
        dst1[1] = src1[1];
        dst2[0] = src2[0];
        dst2[1] = src2[1];

        src += 2 * src_stride;
        dst += 2 * dst_stride;
    }
}
