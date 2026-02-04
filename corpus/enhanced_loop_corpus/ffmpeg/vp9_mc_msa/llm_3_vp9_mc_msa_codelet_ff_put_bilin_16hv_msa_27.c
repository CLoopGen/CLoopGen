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
for (loop_cnt = (height >> 2); loop_cnt--;) {
    int offset;
    const int block_size = 4;
    for (offset = 0; offset < block_size; offset++) {
        uint8_t *current_src = src + offset * src_stride;
        uint8_t *current_dst = dst + offset * dst_stride;

        current_dst[0] = current_src[0];
        current_dst[1] = current_src[1];
        current_dst[2] = current_src[2];
        current_dst[3] = current_src[3];
    }

    src += 4 * src_stride;
    dst += 4 * dst_stride;
}
}
