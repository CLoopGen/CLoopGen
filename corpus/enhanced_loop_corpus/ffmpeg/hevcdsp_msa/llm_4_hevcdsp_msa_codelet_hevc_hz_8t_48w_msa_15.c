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
        if (src_stride > 0) {
            src += src_stride;
        } else {
            src -= src_stride;
        }
        if (dst_stride != 0) {
            dst += dst_stride;
        }
    }
}
