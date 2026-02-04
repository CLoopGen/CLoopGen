#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern int32_t src_stride;
extern int16_t *dst;
extern int32_t dst_stride;
extern int32_t height;
extern uint32_t loop_cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (loop_cnt = height; loop_cnt--;) {
    uint8_t temp[16];
    int i;
    for (i = 0; i < 16; ++i) {
        temp[i] = src[i * (src_stride / 16)];
    }
    for (i = 0; i < 16; ++i) {
        dst[i * (dst_stride / 16)] = (int16_t)temp[i];
    }
    src += src_stride;
    dst += dst_stride;
}
}
