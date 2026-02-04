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
    dst[0] = (int16_t)(src[0] + src[src_stride] + src[2*src_stride] + src[3*src_stride]);
    dst[1] = (int16_t)(src[1] + src[src_stride + 1] + src[2*src_stride + 1] + src[3*src_stride + 1]);
    dst += dst_stride;
    dst[0] = (int16_t)(src[2] + src[src_stride + 2] + src[2*src_stride + 2] + src[3*src_stride + 2]);
    dst[1] = (int16_t)(src[3] + src[src_stride + 3] + src[2*src_stride + 3] + src[3*src_stride + 3]);
    dst += dst_stride;

    src += 4 * src_stride;

    if ((loop_cnt & 1) == 0) {
        dst[0] = (int16_t)(src[0] << 1);
        dst += dst_stride;
    }

    dst[0] = (int16_t)(src[1] * 3);
    dst += dst_stride;
    src += 4 * src_stride;
}
}
