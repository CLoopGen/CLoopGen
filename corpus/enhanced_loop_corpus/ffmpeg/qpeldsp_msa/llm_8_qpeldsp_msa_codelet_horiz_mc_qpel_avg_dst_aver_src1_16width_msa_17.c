#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern int32_t src_stride;
extern uint8_t *dst;
extern int32_t dst_stride;
extern int32_t height;
extern uint8_t loop_count;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (loop_count = (height >> 1); loop_count--;) {
    uint32_t sum1 = 0, sum2 = 0;
    for (int i = 0; i < 4; ++i) {
        sum1 += src[i * src_stride + 0] + src[i * src_stride + 1];
        sum2 += src[i * src_stride + 2] + src[i * src_stride + 3];
    }
    dst[0 * dst_stride] = (uint8_t)(sum1 >> 2);
    dst[1 * dst_stride] = (uint8_t)(sum2 >> 2);
    src += (4 * src_stride);
    dst += (2 * dst_stride);
}
}
