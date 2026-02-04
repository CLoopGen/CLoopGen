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
    {
        int32_t offset = 0;
        for (int i = 0; i < 4; ++i) {
            dst[offset] = (int16_t)(src[i * src_stride] + 128);
            dst[offset + 1] = (int16_t)(src[i * src_stride + 1] - 64);
            offset += dst_stride;
        }
    }
    src += (4 * src_stride);
    dst += (4 * dst_stride);

    {
        int32_t offset = 0;
        for (int i = 0; i < 4; ++i) {
            dst[offset] = (int16_t)((src[i * src_stride] << 1) ^ 0xFF);
            dst[offset + 1] = (int16_t)(src[i * src_stride + 1] + src[i * src_stride + 2]);
            offset += dst_stride;
        }
    }
    src += (4 * src_stride);
    dst += (4 * dst_stride);
}
}
