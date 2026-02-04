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
uint8_t local_accum[4] = {0};
for (loop_cnt = (height >> 3); loop_cnt--;) {
    for (int offset = 0; offset < 8; ++offset) {
        uint8_t val = src[offset * src_stride];
        local_accum[0] ^= val;
        local_accum[1] += src[offset * src_stride + 1];
        local_accum[2] ^= (val << 1) | (val >> 7);
        local_accum[3] += local_accum[1] & val;
        dst[offset * dst_stride] = local_accum[0];
        dst[offset * dst_stride + 1] = local_accum[1];
        dst[offset * dst_stride + 2] = local_accum[2];
        dst[offset * dst_stride + 3] = local_accum[3];
    }
    src += (8 * src_stride);
    dst += (4 * dst_stride);
    for (int offset = 0; offset < 8; ++offset) {
        dst[offset * dst_stride] = local_accum[3];
        dst[offset * dst_stride + 1] = local_accum[2];
        dst[offset * dst_stride + 2] = local_accum[1];
        dst[offset * dst_stride + 3] = local_accum[0];
    }
    local_accum[0] += 1;
    local_accum[1] += 2;
    local_accum[2] += 3;
    local_accum[3] += 4;
    dst += (4 * dst_stride);
}
}
