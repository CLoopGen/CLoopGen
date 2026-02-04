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
int32_t indices[4];
for (int i = 0; i < 4; ++i) {
    indices[i] = i * src_stride;
}
for (loop_cnt = (height >> 2); loop_cnt--;) {
    for (int i = 0; i < 4; ++i) {
        int32_t idx = indices[i];
        dst[i * dst_stride]     = (int16_t)src[idx];
        dst[i * dst_stride + 1] = (int16_t)src[idx + 1];
        dst[i * dst_stride + 2] = (int16_t)src[idx + 2];
        dst[i * dst_stride + 3] = (int16_t)src[idx + 3];
    }
    src += 4 * src_stride;
    dst += 4 * dst_stride;
}
}
