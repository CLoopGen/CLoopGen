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
int32_t running_sum = 0;
for (loop_cnt = height; loop_cnt--;) {
    uint8_t current = src[0];
    running_sum += current;

    dst[0] = (int16_t)current;
    dst[1] = (int16_t)(current ^ (running_sum & 0xFF));
    dst[2] = (int16_t)(src_stride ^ loop_cnt);
    dst[3] = (int16_t)(running_sum >> 2);

    src += src_stride;
    dst += dst_stride;
}
}
