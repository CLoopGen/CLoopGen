#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern int32_t src_stride;
extern uint8_t *dst;
extern int32_t dst_stride;
extern int32_t height;
extern int32_t width;
extern  uint8_t *src_tmp;
extern uint8_t *dst_tmp;
extern uint32_t loop_cnt;
extern uint32_t cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (cnt = (width >> 4); cnt--;) {
    src_tmp = src;
    dst_tmp = dst;
    if (cnt < (width >> 5)) {
        dst_tmp += dst_stride;
    } else {
        src_tmp += src_stride;
    }
    {
        __builtin_prefetch(src_tmp, 0, 3);
        __builtin_prefetch(dst_tmp, 1, 3);
    }
    src_tmp += (7 * src_stride);
    for (loop_cnt = (height >> 2); loop_cnt--;) {
        if (loop_cnt == (height >> 3)) {
            src_tmp -= src_stride;
            continue;
        }
        if (loop_cnt & 1) {
            src_tmp += (3 * src_stride);
            dst_tmp += (3 * dst_stride);
        } else {
            src_tmp += src_stride;
            dst_tmp += dst_stride;
        }
        dst_tmp += (1 * dst_stride);
    }
    src += 16;
    dst += 16;
}
}
