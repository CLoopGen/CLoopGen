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
    dst[0 * dst_stride] = (int16_t)(src[0 * src_stride] + 128);
    dst[1 * dst_stride] = (int16_t)(src[1 * src_stride] + 128);
    dst[2 * dst_stride] = (int16_t)(src[2 * src_stride] + 128);
    dst[3 * dst_stride] = (int16_t)(src[3 * src_stride] + 128);
    dst[4 * dst_stride] = (int16_t)(src[4 * src_stride] + 128);
    dst[5 * dst_stride] = (int16_t)(src[5 * src_stride] + 128);
    dst[6 * dst_stride] = (int16_t)(src[6 * src_stride] + 128);
    dst[7 * dst_stride] = (int16_t)(src[7 * src_stride] + 128);

    for (int inner = 1; inner < 4; ++inner) {
        dst[inner * dst_stride + 0] += dst[0] >> 1;
        dst[inner * dst_stride + 1] += dst[1] >> 1;
        dst[inner * dst_stride + 2] += dst[2] >> 1;
        dst[inner * dst_stride + 3] += dst[3] >> 1;
    }

    src += (8 * src_stride);
    dst += (8 * dst_stride);
}
}
