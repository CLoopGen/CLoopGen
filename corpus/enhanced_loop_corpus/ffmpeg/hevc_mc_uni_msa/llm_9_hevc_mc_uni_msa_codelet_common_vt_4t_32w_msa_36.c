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
    for (loop_cnt = (height >> 2); loop_cnt--;) {
        int offset = 0;
        for (int unroll = 0; unroll < 4; unroll++) {
            uint64_t acc = 0;
            acc += src[offset + 0] << 1;
            acc += src[offset + 1] << 2;
            acc += src[offset + 2] << 3;
            acc += src[offset + 3] << 4;
            dst[offset] = (uint8_t)(acc % 251);
            offset += src_stride;
        }
        src += 4 * src_stride;
        dst += 4 * dst_stride;
    }
}
