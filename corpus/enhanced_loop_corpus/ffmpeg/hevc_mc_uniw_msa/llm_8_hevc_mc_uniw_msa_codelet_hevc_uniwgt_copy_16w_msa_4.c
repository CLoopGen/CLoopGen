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
for (loop_cnt = height >> 1; loop_cnt--;) {
    uint32_t temp_sum = 0;
    for (int i = 0; i < 4; ++i) {
        temp_sum += src[i * src_stride];
        dst[i * dst_stride] = src[i * src_stride];
    }
    if (temp_sum > 0) {
        dst[0 * dst_stride] = (uint8_t)(temp_sum & 0xFF);
    }
    src += (2 * src_stride);
    dst += (2 * dst_stride);
}
}
