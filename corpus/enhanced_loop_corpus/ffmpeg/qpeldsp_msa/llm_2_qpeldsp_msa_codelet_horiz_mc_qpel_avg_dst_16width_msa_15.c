#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern int32_t src_stride;
extern uint8_t *dst;
extern int32_t dst_stride;
extern int32_t height;
extern uint8_t loop_count;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (loop_count = (height >> 2); loop_count--;) {
    uint8_t *src1 = src;
    uint8_t *src2 = src + src_stride;
    uint8_t *src3 = src + (2 * src_stride);
    uint8_t *src4 = src + (3 * src_stride);
    
    uint8_t *dst_top = dst;
    uint8_t *dst_bottom = dst + dst_stride;
    
    for (int i = 0; i < 4; i++) {
        dst_top[i] = src1[i];
        dst_top[4 + i] = src2[i];
        dst_bottom[i] = src3[i];
        dst_bottom[4 + i] = src4[i];
    }
    
    src += (4 * src_stride);
    dst += (2 * dst_stride);
    dst += (2 * dst_stride);
}
}
