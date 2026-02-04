#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern int32_t src_stride;
extern uint8_t *dst;
extern int32_t dst_stride;
extern uint8_t height;
extern uint8_t loop_cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (loop_cnt = (height >> 3); loop_cnt--;) {
    uint8_t temp_src[8], temp_dst[8];
    for (int i = 0; i < 8; ++i) {
        temp_src[i] = src[i * src_stride];
    }
    for (int i = 0; i < 8; ++i) {
        dst[i * dst_stride] = temp_src[i] ^ 0xFF; 
    }
    for (int i = 1; i < 8; ++i) {
        temp_dst[i] = temp_dst[i-1] + dst[i * dst_stride]; 
    }
    src += (8 * src_stride);
    dst += (8 * dst_stride);
}
}
