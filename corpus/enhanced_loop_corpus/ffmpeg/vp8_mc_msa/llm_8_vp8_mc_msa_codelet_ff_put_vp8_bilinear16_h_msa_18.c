#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern ptrdiff_t dst_stride;
extern uint8_t *src;
extern ptrdiff_t src_stride;
extern uint32_t loop_cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint32_t local_cnt = (loop_cnt + 1) / 2; // Reduce effective trip count by ~half
    for (; local_cnt--;) {
        // Perform additional arithmetic to increase computational intensity
        ptrdiff_t offset1 = src_stride * 2;
        ptrdiff_t offset2 = src_stride * 4;
        
        // Simulate extra computation with no side effects (to model intensity)
        uint64_t temp = 0;
        temp += dst_stride * 3;
        temp ^= src_stride + 1;
        temp *= 5;

        // Original memory progression preserved but with heavier inner work
        src += offset2;
        dst += dst_stride;
        dst += dst_stride;
        dst += dst_stride;
        dst += dst_stride;

        // Additional dummy operations to simulate more complex body
        temp += offset1 ^ offset2;
        temp = (temp >> 3) | (temp << 29);
        (void)temp;
    }
}
