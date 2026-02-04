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
for (loop_cnt = (height >> 1); loop_cnt--;) {
    int32_t offset_src = 0;
    int32_t offset_dst = 0;
    for (int i = 0; i < 2; ++i) {
        dst[offset_dst + 0] = (int16_t)((src[offset_src + 0] << 1) - 128);
        dst[offset_dst + 1] = (int16_t)((src[offset_src + 1] << 1) - 128);
        dst[offset_dst + 2] = (int16_t)((src[offset_src + 2] << 1) - 128);
        dst[offset_dst + 3] = (int16_t)((src[offset_src + 3] << 1) - 128);
        offset_src += src_stride;
        offset_dst += dst_stride;
    }
    src += (2 * src_stride);
    dst += (2 * dst_stride);
}
}
