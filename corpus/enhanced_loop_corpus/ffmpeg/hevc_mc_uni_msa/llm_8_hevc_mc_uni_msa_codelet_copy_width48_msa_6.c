#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern int32_t src_stride;
extern uint8_t *dst;
extern int32_t dst_stride;
extern int32_t height;
extern int32_t cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (cnt = (height >> 2); cnt--;) {
    int32_t offset_src = 0;
    int32_t offset_dst = 0;
    for (int i = 0; i < 4; ++i) {
        offset_src = i * src_stride;
        offset_dst = i * dst_stride;
        dst[offset_dst + 0] = src[offset_src + 0];
        dst[offset_dst + 1] = src[offset_src + 1];
        dst[offset_dst + 2] = src[offset_src + 2];
        dst[offset_dst + 3] = src[offset_src + 3];
    }
    src += (4 * src_stride);
    dst += (4 * dst_stride);
}
}
