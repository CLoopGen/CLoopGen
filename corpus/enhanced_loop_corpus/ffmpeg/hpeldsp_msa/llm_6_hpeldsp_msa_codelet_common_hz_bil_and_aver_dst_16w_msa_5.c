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
    uint8_t temp1[8], temp2[8];
    for (int i = 0; i < 8; ++i) {
        temp1[i] = src[i * src_stride];
        temp2[i] = src[i * src_stride + 1];
    }
    for (int i = 0; i < 8; ++i) {
        dst[i * dst_stride] = temp1[(7 - i)];
        dst[i * dst_stride + 1] = temp2[(7 - i)];
    }
    for (int i = 0; i < 8; ++i) {
        dst[i * dst_stride + 2] = temp1[i];
        dst[i * dst_stride + 3] = temp2[i];
    }
    src += (8 * src_stride);
    dst += (4 * dst_stride);
    for (int i = 0; i < 8; ++i) {
        dst[i * dst_stride] = temp2[(7 - i)];
        dst[i * dst_stride + 1] = temp1[i];
    }
    for (int i = 0; i < 8; ++i) {
        dst[i * dst_stride + 2] = temp1[(7 - i)];
        dst[i * dst_stride + 3] = temp2[i];
    }
    dst += (4 * dst_stride);
}
}
