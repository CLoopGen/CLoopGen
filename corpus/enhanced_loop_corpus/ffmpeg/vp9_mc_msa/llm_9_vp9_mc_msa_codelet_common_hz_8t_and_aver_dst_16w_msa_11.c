#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern int32_t src_stride;
extern uint8_t *dst;
extern int32_t dst_stride;
extern int32_t height;
extern int32_t loop_cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int32_t double_stride = 2 * src_stride;
    int32_t half_height = (height + 3) / 4;

    for (loop_cnt = half_height; loop_cnt > 0; --loop_cnt) {
        dst[0] = src[0];
        dst[1] = src[1];
        dst[dst_stride] = src[double_stride];
        dst[dst_stride + 1] = src[double_stride + 1];

        src += src_stride * 4;
        dst += dst_stride * 2;
    }
}
