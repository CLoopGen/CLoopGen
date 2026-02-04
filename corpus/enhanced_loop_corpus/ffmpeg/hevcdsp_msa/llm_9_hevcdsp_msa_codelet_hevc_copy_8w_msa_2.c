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
for (loop_cnt = (height >> 3); loop_cnt--;) {
    int j;
    for (j = 0; j < 8; ++j) {
        int offset_s = j * src_stride;
        int offset_d = j * dst_stride;
        dst[offset_d] = (int16_t)(src[offset_s] + 128);
        dst[offset_d + 1] = (int16_t)(src[offset_s + 1] + 128);
        dst[offset_d + 2] = (int16_t)(src[offset_s + 2] + 128);
        dst[offset_d + 3] = (int16_t)(src[offset_s + 3] + 128);
        dst[offset_d + 4] = (int16_t)(src[offset_s + 4] + 128);
        dst[offset_d + 5] = (int16_t)(src[offset_s + 5] + 128);
        dst[offset_d + 6] = (int16_t)(src[offset_s + 6] + 128);
        dst[offset_d + 7] = (int16_t)(src[offset_s + 7] + 128);
    }
    src += (8 * src_stride);
    dst += (8 * dst_stride);
}
}
