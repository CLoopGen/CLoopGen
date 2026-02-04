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
extern int16_t *dst_tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (loop_cnt = (height >> 2); loop_cnt--;) {
        int32_t offset = loop_cnt * dst_stride;
        dst_tmp[offset + 0] = src[0];
        dst_tmp[offset + 1] = src[src_stride];
        dst_tmp[offset + 2] = src[2 * src_stride];
        dst_tmp[offset + 3] = src[3 * src_stride];

        dst[0] = (int16_t)(src[0] << 2);
        dst[dst_stride] = (int16_t)(src[src_stride] << 2);
        dst[2 * dst_stride] = (int16_t)(src[2 * src_stride] << 2);
        dst[3 * dst_stride] = (int16_t)(src[3 * src_stride] << 2);

        src += 4 * src_stride;
        dst += 4 * dst_stride;
        dst_tmp += 4 * dst_stride;
    }
}
