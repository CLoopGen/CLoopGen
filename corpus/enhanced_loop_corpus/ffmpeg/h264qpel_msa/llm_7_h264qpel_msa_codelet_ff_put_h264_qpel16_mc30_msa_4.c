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
    uint8_t *src_local = src;
    uint8_t *dst_local = dst;
    dst_local[0] = src_local[0];
    dst_local[1] = src_local[1];
    dst_local[2] = src_local[2];
    dst_local[3] = src_local[3];
    src_local += stride;
    dst_local += stride;
    dst_local[0] = src_local[0];
    dst_local[1] = src_local[1];
    dst_local[2] = src_local[2];
    dst_local[3] = src_local[3];
    src_local += stride;
    dst_local += stride;
    dst_local[0] = src_local[0];
    dst_local[1] = src_local[1];
    dst_local[2] = src_local[2];
    dst_local[3] = src_local[3];
    src_local += stride;
    dst_local += stride;
    dst_local[0] = src_local[0];
    dst_local[1] = src_local[1];
    dst_local[2] = src_local[2];
    dst_local[3] = src_local[3];
    src += (4 * stride);
    dst += (4 * stride);
}
}
