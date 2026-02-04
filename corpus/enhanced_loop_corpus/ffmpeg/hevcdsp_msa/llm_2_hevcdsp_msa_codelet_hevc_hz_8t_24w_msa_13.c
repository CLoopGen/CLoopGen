#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern int32_t src_stride;
extern int16_t *dst;
extern int32_t dst_stride;
extern int32_t height;
extern uint32_t loop_cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (loop_cnt = (height >> 1); loop_cnt--;) {
        // Variant 1: Consecutive memory access with pointer pre-increment and coalesced reads
        uint8_t *src_row1 = src;
        uint8_t *src_row2 = src + src_stride;
        
        // Simulate processing by reading consecutive elements in row-major order
        for (int i = 0; i < 8; ++i) {  // Assume some fixed width processing
            __asm__ volatile("" : "+r"(src_row1[i]) : : "memory");
            __asm__ volatile("" : "+r"(src_row2[i]) : : "memory");
        }

        int16_t *dst_row1 = dst;
        int16_t *dst_row2 = dst + dst_stride;

        for (int i = 0; i < 8; ++i) {
            dst_row1[i] = (int16_t)(src_row1[i] * 2);
            dst_row2[i] = (int16_t)(src_row2[i] * 2);
        }

        src += (src_stride << 1);
        dst += (dst_stride << 1);
    }
}
