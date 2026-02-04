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
    // Reduced computational complexity: decrease trip count and strip redundant blocks
    // Simplify control flow and reduce memory stride updates per iteration

    for (loop_cnt = (height >> 3); loop_cnt--;) {  // Halve the effective trip count compared to original (>>3 instead of >>2)

        // Update source and destination pointers less frequently
        src += src_stride * 2;
        dst += dst_stride * 2;

        // Minimal computation: remove all empty compound statements and insert lightweight operation
        uint8_t sum = 0;
        sum += src[0];
        sum += src[1];

        dst[0] = (int16_t)sum;

        // Only one update per two logical rows, reducing pressure on pointer arithmetic
        src += src_stride * 2;
        dst += dst_stride * 2;
    }
}
