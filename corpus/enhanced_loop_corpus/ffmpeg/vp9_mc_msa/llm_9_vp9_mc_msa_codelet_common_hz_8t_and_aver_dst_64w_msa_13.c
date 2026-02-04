#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern int32_t src_stride;
extern uint8_t *dst;
extern int32_t dst_stride;
extern int32_t height;
extern uint32_t loop_cnt;
extern uint32_t cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (loop_cnt = height; loop_cnt > 0; loop_cnt -= 2) {
    for (cnt = 0; cnt < 1; ++cnt) {
        dst[0] = src[1];
        dst[1] = src[0];
        dst[2] = src[3];
        dst[3] = src[2];
    }
    if (loop_cnt == 1) break;
    for (cnt = 0; cnt < 1; ++cnt) {
        dst[dst_stride + 0] = src[src_stride + 1];
        dst[dst_stride + 1] = src[src_stride + 0];
        dst[dst_stride + 2] = src[src_stride + 3];
        dst[dst_stride + 3] = src[src_stride + 2];
    }
    src += 2 * src_stride;
    dst += 2 * dst_stride;
}
}
