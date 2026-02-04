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
for (loop_cnt = height >> 1; loop_cnt--;) {
    uint8_t temp1, temp2;
    temp1 = src[0];
    temp2 = src[src_stride];
    dst[0] = temp1 ^ 0xFF;
    dst[dst_stride] = temp2 ^ 0xFF;
    src += (2 * src_stride);
    dst += (2 * dst_stride);
}
}
