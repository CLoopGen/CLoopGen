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
for (loop_cnt = height; loop_cnt--;) {
    int32_t temp_src_offset = src_stride * 1;
    uint8_t val1 = src[0];
    uint8_t val2 = src[temp_src_offset];
    uint8_t sum = val1 + val2;
    dst[0] = (int16_t)sum;
    
    src += src_stride;
    dst += dst_stride;
}
}
