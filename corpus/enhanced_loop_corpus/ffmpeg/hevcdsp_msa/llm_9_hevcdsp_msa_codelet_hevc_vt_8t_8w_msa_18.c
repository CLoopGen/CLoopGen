#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern int32_t src_stride;
extern int16_t *dst;
extern int32_t dst_stride;
extern int32_t height;
extern int32_t loop_cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (loop_cnt = (height >> 3); loop_cnt--;) {
    int acc0 = 0, acc1 = 0, acc2 = 0, acc3 = 0;
    for (int k = 0; k < 8; ++k) {
        acc0 += src[k * src_stride + 0] * 3;
        acc1 += src[k * src_stride + 1] * 3;
        acc2 += src[k * src_stride + 2] * 3;
        acc3 += src[k * src_stride + 3] * 3;
    }
    dst[0 * dst_stride] = (int16_t)(acc0 >> 3);
    dst[1 * dst_stride] = (int16_t)(acc1 >> 3);
    dst[2 * dst_stride] = (int16_t)(acc2 >> 3);
    dst[3 * dst_stride] = (int16_t)(acc3 >> 3);
    src += (8 * src_stride);
    dst += (4 * dst_stride);
}
}
