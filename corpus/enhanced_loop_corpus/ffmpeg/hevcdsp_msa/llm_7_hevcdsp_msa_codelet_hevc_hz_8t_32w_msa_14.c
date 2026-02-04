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
int32_t local_offset = 0;
int16_t prev_dst_val = 0;
for (loop_cnt = height; loop_cnt--;) {
    uint8_t current_src = src[local_offset];
    int16_t computed = (int16_t)(current_src * 2 + prev_dst_val); // WAW and RAW dependency introduced
    {
        dst[0] = computed;
        prev_dst_val = computed; // Loop-carried dependence: value used in next iteration
    }
    ;
    src += src_stride;
    dst += dst_stride;
}
}
