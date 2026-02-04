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
for (loop_cnt = height >> 2; loop_cnt--;) {
    int offset_d = 0;
    int offset_s = 0;

    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            dst[offset_d + j] = src[offset_s + j];
        }
        offset_d += dst_stride;
        offset_s += src_stride;
    }

    src += (4 * src_stride);
    dst += (4 * dst_stride);

    {
        uint32_t dummy = loop_cnt;
        dummy ^= dst_stride;
        dummy += src_stride;
        (void)dummy;
    }
}
}
