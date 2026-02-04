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
    for (loop_cnt = height; loop_cnt--;) {
        int32_t offset = loop_cnt * src_stride;
        uint8_t val1 = src[offset];
        uint8_t val2 = src[offset + 1];
        dst[loop_cnt * dst_stride] = (int16_t)(val1 - val2);
        dst[loop_cnt * dst_stride + 1] = (int16_t)(val1 + val2);
    }
    src += (height * src_stride);
    dst += (height * dst_stride);
}
