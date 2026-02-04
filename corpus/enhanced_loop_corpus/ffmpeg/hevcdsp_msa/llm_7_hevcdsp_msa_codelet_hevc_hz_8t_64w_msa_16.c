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
int32_t local_dst_stride = dst_stride;
int32_t accumulated_offset = 0;

for (loop_cnt = height; loop_cnt--;) {
    accumulated_offset += local_dst_stride;
    
    int16_t computed_val = (int16_t)(src[0] * 2);
    dst[accumulated_offset / sizeof(int16_t)] = computed_val;
    
    src += src_stride;
}
}
