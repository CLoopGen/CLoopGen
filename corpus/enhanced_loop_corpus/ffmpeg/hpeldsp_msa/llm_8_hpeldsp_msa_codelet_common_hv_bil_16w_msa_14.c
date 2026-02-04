#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern int32_t src_stride;
extern uint8_t *dst;
extern int32_t dst_stride;
extern uint8_t height;
extern uint8_t loop_cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (loop_cnt = (height >> 2); loop_cnt--;) {
    uint8_t *temp_src = src;
    uint8_t *temp_dst = dst;
    for (int i = 0; i < 4; ++i) {
        temp_dst[0] = temp_src[0];
        temp_dst[1] = temp_src[1];
        temp_dst[2] = temp_src[2];
        temp_dst[3] = temp_src[3];
        temp_src += src_stride;
        temp_dst += dst_stride;
    }
    src += (4 * src_stride);
    dst += (4 * dst_stride);
}
}
