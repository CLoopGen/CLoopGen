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
for (loop_cnt = height >> 3; loop_cnt--;) {
    uint64_t acc0 = 0, acc1 = 0, acc2 = 0, acc3 = 0;
    acc0 += src[0 * src_stride + 0]; acc0 += src[1 * src_stride + 1];
    acc1 += src[2 * src_stride + 2]; acc1 += src[3 * src_stride + 3];
    acc2 += src[4 * src_stride + 4]; acc2 += src[5 * src_stride + 5];
    acc3 += src[6 * src_stride + 6]; acc3 += src[7 * src_stride + 7];

    dst[0 * dst_stride + 0] = (uint8_t)(acc0 & 0xFF);
    dst[1 * dst_stride + 1] = (uint8_t)(acc1 & 0xFF);
    dst[2 * dst_stride + 2] = (uint8_t)(acc2 & 0xFF);
    dst[3 * dst_stride + 3] = (uint8_t)(acc3 & 0xFF);

    for (int k = 0; k < 2; ++k) {
        acc0 += acc1 + acc2 + acc3;
        dst[(4 + k)*dst_stride] = (uint8_t)((acc0 >> (k*8)) & 0xFF);
    }

    src += (8 * src_stride);
    dst += (8 * dst_stride);
}
}
