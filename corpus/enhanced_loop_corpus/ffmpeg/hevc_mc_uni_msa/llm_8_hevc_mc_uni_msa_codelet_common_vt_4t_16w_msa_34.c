#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern int32_t src_stride;
extern uint8_t *dst;
extern int32_t dst_stride;
extern int32_t height;
extern uint32_t loop_cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (loop_cnt = (height >> 1); loop_cnt--;) {
        uint32_t i;
        for (i = 0; i < 4; ++i) {
            dst[i * dst_stride] = src[i * src_stride];
            dst[i * dst_stride + 1] = src[i * src_stride + 1];
        }
        src += (2 * src_stride);
        dst += (2 * dst_stride);
    }
}
