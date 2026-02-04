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
for (loop_cnt = 64; loop_cnt--;) {
    uint8_t temp_src[8];
    uint8_t temp_dst[8];
    
    // Load 8 consecutive bytes using unit stride from src and dst
    for (int i = 0; i < 8; ++i) {
        temp_src[i] = src[i];
        temp_dst[i] = dst[i];
    }
    
    // Perform simple transformation: XOR each byte
    for (int i = 0; i < 8; ++i) {
        temp_dst[i] ^= temp_src[i];
    }
    
    // Store back with unit stride
    for (int i = 0; i < 8; ++i) {
        dst[i] = temp_dst[i];
    }
    
    // Update pointers with original strides
    src += src_stride;
    dst += dst_stride;
}
}
