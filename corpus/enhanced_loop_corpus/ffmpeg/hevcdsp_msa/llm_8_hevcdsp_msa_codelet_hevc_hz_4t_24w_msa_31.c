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
    for (loop_cnt = height; loop_cnt--;) {
        dst_tmp[0] = (int16_t)(src[0] * 2 + 1);
        dst_tmp[1] = (int16_t)(src[1] * 2 + 1);
        dst_tmp += dst_stride;
        src += src_stride;
    }
}
