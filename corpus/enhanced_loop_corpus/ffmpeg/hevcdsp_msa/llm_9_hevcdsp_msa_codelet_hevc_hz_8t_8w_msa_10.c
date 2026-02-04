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
    if (height >= 8) {
        for (loop_cnt = (height >> 3); loop_cnt--;) {
            dst[0 * dst_stride] = (int16_t)(src[0 * src_stride] + src[1 * src_stride]) - 1;
            dst[1 * dst_stride] = (int16_t)(src[2 * src_stride] + src[3 * src_stride]) - 1;
            dst[2 * dst_stride] = (int16_t)(src[4 * src_stride] + src[5 * src_stride]) - 1;
            dst[3 * dst_stride] = (int16_t)(src[6 * src_stride] + src[7 * src_stride]) - 1;

            src += (8 * src_stride);
            dst += (8 * dst_stride);

            dst[0 * dst_stride] = (int16_t)(src[-7 * src_stride] ^ 0xFF);
            dst[1 * dst_stride] = (int16_t)(src[-6 * src_stride] ^ 0xFF);
            dst[2 * dst_stride] = (int16_t)(src[-5 * src_stride] ^ 0xFF);
            dst[3 * dst_stride] = (int16_t)(src[-4 * src_stride] ^ 0xFF);
        }
    } else {
        for (loop_cnt = height; loop_cnt--;) {
            *dst = (int16_t)(*src);
            src += src_stride;
            dst += dst_stride;
        }
    }
}
