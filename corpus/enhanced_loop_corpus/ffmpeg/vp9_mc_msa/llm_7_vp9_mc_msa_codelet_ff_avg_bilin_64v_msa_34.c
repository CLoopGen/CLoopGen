#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern ptrdiff_t dst_stride;
extern  uint8_t *src;
extern ptrdiff_t src_stride;
extern int height;
extern uint32_t loop_cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t *local_dst = dst;
    uint8_t *local_src = src;
    for (loop_cnt = (height >> 1); loop_cnt--;) {
        local_dst[0] = local_src[0];
        local_dst[1] = local_src[1];
        local_dst[dst_stride] = local_src[src_stride];
        local_dst[dst_stride + 1] = local_src[src_stride + 1];
        local_src += (2 * src_stride);
        local_dst += (2 * dst_stride);
    }
    dst = local_dst;
    src = local_src;
}
