#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern int32_t src_stride;
extern uint8_t *dst;
extern int32_t dst_stride;
extern uint8_t height;
extern uint8_t loop_cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (loop_cnt = (height >> 3); loop_cnt--;) {
    int32_t src_offset, dst_offset;
    for (int i = 0; i < 8; i++) {
        src_offset = (i * src_stride);
        dst_offset = (i * dst_stride);
        dst[dst_offset + 0] = src[src_offset + 0];
        dst[dst_offset + 1] = src[src_offset + 1];
        dst[dst_offset + 2] = src[src_offset + 2];
        dst[dst_offset + 3] = src[src_offset + 3];
        dst[dst_offset + 4] = src[src_offset + 4];
        dst[dst_offset + 5] = src[src_offset + 5];
        dst[dst_offset + 6] = src[src_offset + 6];
        dst[dst_offset + 7] = src[src_offset + 7];
    }
    src += (8 * src_stride);
    dst += (8 * dst_stride);
}
}
