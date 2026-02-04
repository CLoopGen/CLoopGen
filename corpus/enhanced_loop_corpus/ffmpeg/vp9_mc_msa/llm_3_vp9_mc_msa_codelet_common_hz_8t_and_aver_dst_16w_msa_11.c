#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern int32_t src_stride;
extern uint8_t *dst;
extern int32_t dst_stride;
extern int32_t height;
extern int32_t loop_cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
const int32_t vec_size = 8;
for (loop_cnt = height >> 1; loop_cnt--;) {
    for (int offset = 0; offset < vec_size; offset++) {
        dst[offset * dst_stride] = src[offset * src_stride];
        dst[offset * dst_stride + dst_stride/2] = src[offset * src_stride + src_stride/2];
    }

    src += (2 * src_stride);
    dst += (2 * dst_stride);
}
}
