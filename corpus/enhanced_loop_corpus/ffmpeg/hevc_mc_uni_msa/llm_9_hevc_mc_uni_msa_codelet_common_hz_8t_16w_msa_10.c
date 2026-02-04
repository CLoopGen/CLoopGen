#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern int32_t src_stride;
extern uint8_t *dst;
extern int32_t dst_stride;
extern int32_t height;
extern uint32_t loop_cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (loop_cnt = (height >> 3); loop_cnt--;) {
    {
        __builtin_prefetch(src, 0, 3);
        __builtin_prefetch(dst, 1, 3);
    }
    src += (4 * src_stride);
    {
        __builtin_prefetch(src, 0, 3);
        __builtin_prefetch(dst + dst_stride, 1, 3);
    }
    src += (4 * src_stride);
    dst += (4 * dst_stride);
    {
        __builtin_prefetch(dst + 2*dst_stride, 1, 3);
    }
    dst += (4 * dst_stride);
}
}
