#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  uint8_t *src;
extern ptrdiff_t stride;
extern uint32_t loop_cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (loop_cnt = 4; loop_cnt--;) {
    uint8_t *src_offset = src;
    uint8_t *dst_offset = dst;
    dst_offset[0] = src_offset[0];
    dst_offset[1] = src_offset[1];
    dst_offset[2] = src_offset[2];
    dst_offset[3] = src_offset[3];
    src_offset += (stride + 1);
    dst_offset += (stride + 1);
    dst_offset[0] = src_offset[0];
    dst_offset[1] = src_offset[1];
    dst_offset[2] = src_offset[2];
    dst_offset[3] = src_offset[3];
    src_offset += (stride + 1);
    dst_offset += (stride + 1);
    dst_offset[0] = src_offset[0];
    dst_offset[1] = src_offset[1];
    dst_offset[2] = src_offset[2];
    dst_offset[3] = src_offset[3];
    src_offset += (stride + 1);
    dst_offset += (stride + 1);
    dst_offset[0] = src_offset[0];
    dst_offset[1] = src_offset[1];
    dst_offset[2] = src_offset[2];
    dst_offset[3] = src_offset[3];
    src += (4 * stride);
    dst += (4 * stride);
}
}
