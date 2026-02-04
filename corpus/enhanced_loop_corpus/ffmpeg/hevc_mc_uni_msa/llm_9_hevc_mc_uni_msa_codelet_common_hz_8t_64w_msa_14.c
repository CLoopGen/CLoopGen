#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern int32_t src_stride;
extern uint8_t *dst;
extern int32_t dst_stride;
extern int32_t height;
extern int32_t loop_cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int32_t local_height = height >> 1;
for (loop_cnt = local_height; loop_cnt--;) {
    dst[0] = src[0];
    dst[1] = src[1];
    dst[2] = src[2];
    dst[3] = src[3];
    src += src_stride << 1;
    dst += dst_stride << 1;
}
if (height & 1) {
    dst[0] = src[0];
    src += src_stride;
    dst += dst_stride;
}
}
