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
        int32_t temp_src = *(int32_t*)src;
        temp_src += src_stride * 2;
        *dst = (int16_t)(temp_src & 0xFFFF);
        src += src_stride;
        dst += dst_stride;
        
        // Unrolled: perform operations equivalent to two iterations in one
        if (--loop_cnt <= 0) break;
        
        temp_src = *(int32_t*)src;
        temp_src += src_stride * 2;
        *(dst + dst_stride/sizeof(int16_t)) = (int16_t)(temp_src & 0xFFFF);
        src += src_stride;
        dst += dst_stride;
    }
}
