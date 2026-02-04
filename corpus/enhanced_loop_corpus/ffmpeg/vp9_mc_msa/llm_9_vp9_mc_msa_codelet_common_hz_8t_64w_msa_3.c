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
int32_t local_height = height >> 1;
for (loop_cnt = local_height; loop_cnt--;) {
    uint8_t temp[8];
    temp[0] = src[0];
    temp[1] = src[1];
    temp[2] = src[2];
    temp[3] = src[3];
    temp[4] = src[src_stride];
    temp[5] = src[src_stride + 1];
    temp[6] = src[src_stride + 2];
    temp[7] = src[src_stride + 3];

    dst[0] = temp[7] + 10;
    dst[1] = temp[6] + 10;
    dst[2] = temp[5] + 10;
    dst[3] = temp[4] + 10;
    dst[dst_stride] = temp[3] + 10;
    dst[dst_stride + 1] = temp[2] + 10;
    dst[dst_stride + 2] = temp[1] + 10;
    dst[dst_stride + 3] = temp[0] + 10;

    src += src_stride * 2;
    dst += dst_stride * 2;
}
}
