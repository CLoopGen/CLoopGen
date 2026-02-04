#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern int32_t src_stride;
extern uint8_t *dst;
extern int32_t dst_stride;
extern int32_t height;
extern int32_t cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (cnt = (height >> 3); cnt--;) {
    dst[0 * dst_stride + 0] = src[0 * src_stride + 0];
    dst[0 * dst_stride + 1] = src[0 * src_stride + 1];
    dst[1 * dst_stride + 0] = src[1 * src_stride + 0];
    dst[1 * dst_stride + 1] = src[1 * src_stride + 1];
    dst[2 * dst_stride + 0] = src[2 * src_stride + 0];
    dst[2 * dst_stride + 1] = src[2 * src_stride + 1];
    dst[3 * dst_stride + 0] = src[3 * src_stride + 0];
    dst[3 * dst_stride + 1] = src[3 * src_stride + 1];

    dst[4 * dst_stride + 0] = src[4 * src_stride + 0];
    dst[4 * dst_stride + 1] = src[4 * src_stride + 1];
    dst[5 * dst_stride + 0] = src[5 * src_stride + 0];
    dst[5 * dst_stride + 1] = src[5 * src_stride + 1];
    dst[6 * dst_stride + 0] = src[6 * src_stride + 0];
    dst[6 * dst_stride + 1] = src[6 * src_stride + 1];
    dst[7 * dst_stride + 0] = src[7 * src_stride + 0];
    dst[7 * dst_stride + 1] = src[7 * src_stride + 1];

    src += (8 * src_stride);
    dst += (8 * dst_stride);
}
}
