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
for (loop_cnt = (height >> 3); loop_cnt--;) {
    int offset;
    
    offset = 0 * src_stride;
    dst[0 * dst_stride + 0] = src[offset + 0]; dst[0 * dst_stride + 1] = src[offset + 1];
    dst[0 * dst_stride + 2] = src[offset + 2]; dst[0 * dst_stride + 3] = src[offset + 3];

    offset = 1 * src_stride;
    dst[1 * dst_stride + 0] = src[offset + 0]; dst[1 * dst_stride + 1] = src[offset + 1];
    dst[1 * dst_stride + 2] = src[offset + 2]; dst[1 * dst_stride + 3] = src[offset + 3];

    offset = 2 * src_stride;
    dst[2 * dst_stride + 0] = src[offset + 0]; dst[2 * dst_stride + 1] = src[offset + 1];
    dst[2 * dst_stride + 2] = src[offset + 2]; dst[2 * dst_stride + 3] = src[offset + 3];

    offset = 3 * src_stride;
    dst[3 * dst_stride + 0] = src[offset + 0]; dst[3 * dst_stride + 1] = src[offset + 1];
    dst[3 * dst_stride + 2] = src[offset + 2]; dst[3 * dst_stride + 3] = src[offset + 3];

    offset = 4 * src_stride;
    dst[4 * dst_stride + 0] = src[offset + 0]; dst[4 * dst_stride + 1] = src[offset + 1];
    dst[4 * dst_stride + 2] = src[offset + 2]; dst[4 * dst_stride + 3] = src[offset + 3];

    offset = 5 * src_stride;
    dst[5 * dst_stride + 0] = src[offset + 0]; dst[5 * dst_stride + 1] = src[offset + 1];
    dst[5 * dst_stride + 2] = src[offset + 2]; dst[5 * dst_stride + 3] = src[offset + 3];

    offset = 6 * src_stride;
    dst[6 * dst_stride + 0] = src[offset + 0]; dst[6 * dst_stride + 1] = src[offset + 1];
    dst[6 * dst_stride + 2] = src[offset + 2]; dst[6 * dst_stride + 3] = src[offset + 3];

    offset = 7 * src_stride;
    dst[7 * dst_stride + 0] = src[offset + 0]; dst[7 * dst_stride + 1] = src[offset + 1];
    dst[7 * dst_stride + 2] = src[offset + 2]; dst[7 * dst_stride + 3] = src[offset + 3];

    src += (8 * src_stride);
    dst += (8 * dst_stride);
}
}
