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
extern int16_t *dst_tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int32_t outer = height >> 1;
    for (loop_cnt = outer; loop_cnt--;) {
        for (uint32_t inner = 2; inner--;) {
            *dst = (int16_t)((*src) + 5);
            *(dst + 1) = (int16_t)(*(src + 1) + 5);
            dst += dst_stride;
            dst_tmp += dst_stride;
        }
        src += src_stride * 2;
    }
}
