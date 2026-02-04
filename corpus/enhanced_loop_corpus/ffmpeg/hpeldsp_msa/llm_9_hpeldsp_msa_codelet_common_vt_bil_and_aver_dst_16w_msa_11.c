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
    {
        int offset = 0;
        for (int unroll = 0; unroll < 8; ++unroll) {
            offset = unroll * src_stride;
            src[offset + 0] += 1; dst[unroll * dst_stride + 0] = src[offset + 0];
            src[offset + 1] += 1; dst[unroll * dst_stride + 1] = src[offset + 1];
            src[offset + 2] += 1; dst[unroll * dst_stride + 2] = src[offset + 2];
            src[offset + 3] += 1; dst[unroll * dst_stride + 3] = src[offset + 3];
        }
    }
    src += 8 * src_stride;
    dst += 8 * dst_stride;
}
}
