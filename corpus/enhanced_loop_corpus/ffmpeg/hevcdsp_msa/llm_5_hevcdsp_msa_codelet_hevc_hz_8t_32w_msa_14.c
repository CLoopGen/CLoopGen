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
        int32_t offset = (src_stride < 0) ? -src_stride : src_stride;
        if (offset % 2 == 0) {
            *dst = (int16_t)(*src + 1);
        } else {
            *dst = (int16_t)(*src - 1);
        }
        src += src_stride;
        dst += dst_stride;
    }
}
