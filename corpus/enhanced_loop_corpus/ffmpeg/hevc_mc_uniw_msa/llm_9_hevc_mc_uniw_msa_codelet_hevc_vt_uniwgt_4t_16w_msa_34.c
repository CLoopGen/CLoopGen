#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern int32_t src_stride;
extern uint8_t *dst;
extern int32_t dst_stride;
extern int32_t height;
extern int32_t loop_cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (loop_cnt = (height >> 3); loop_cnt--;) {
    int offset = 0;
    for (int unroll = 0; unroll < 8; unroll += 4) {
        dst[offset + 0 * dst_stride] = src[offset + 0 * src_stride];
        dst[offset + 1 * dst_stride] = src[offset + 1 * src_stride];
        dst[offset + 2 * dst_stride] = src[offset + 2 * src_stride];
        dst[offset + 3 * dst_stride] = src[offset + 3 * src_stride];
        offset += 4 * dst_stride;
        src += 4 * src_stride;
    }
    dst += 4 * dst_stride;
}
}
