#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern int32_t src_stride;
extern uint8_t *dst;
extern int32_t dst_stride;
extern uint32_t loop_cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided access with increasing stride per iteration to simulate irregular pattern
    int32_t temp_src_stride = src_stride;
    int32_t temp_dst_stride = dst_stride;
    
    for (loop_cnt = 64; loop_cnt--;) {
        // Modify effective stride based on iteration count to create varying access pattern
        int index_offset = (63 - loop_cnt) * 8; // Increasing offset modulation
        
        uint8_t* s = src + temp_src_stride + index_offset;
        uint8_t* d = dst + temp_dst_stride + index_offset;
        
        // Perform strided write every 8th byte, simulating sparse memory interaction
        for (int j = 0; j < 8; ++j) {
            d[j * 8] = s[-j * 8];
        }

        // Update base pointers for next iteration
        src += src_stride;
        dst += dst_stride;
    }
}
