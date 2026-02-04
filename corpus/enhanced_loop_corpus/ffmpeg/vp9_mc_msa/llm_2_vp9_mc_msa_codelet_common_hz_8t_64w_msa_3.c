#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern int32_t src_stride;
extern uint8_t *dst;
extern int32_t dst_stride;
extern int32_t height;
extern int32_t loop_cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (loop_cnt = height; loop_cnt--;) {
    uint8_t temp_src[16], temp_dst[16];
    int i;
    for (i = 0; i < 16; ++i) {
        temp_src[i] = src[i * (src_stride / 16)];
    }
    for (i = 0; i < 16; ++i) {
        dst[i * (dst_stride / 16)] = temp_src[i] ^ 0xFF;
    }
    src += src_stride;
    dst += dst_stride;
}
}
