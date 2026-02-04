#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern int32_t src_stride;
extern int16_t *dst;
extern int32_t dst_stride;
extern int32_t height;
extern int32_t loop_cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
const int32_t src_offset_a = 0;
const int32_t src_offset_b = src_stride;
const int32_t src_offset_c = 2 * src_stride;
const int32_t src_offset_d = 3 * src_stride;

const int32_t dst_offset_a = 0;
const int32_t dst_offset_b = dst_stride;
const int32_t dst_offset_c = 2 * dst_stride;
const int32_t dst_offset_d = 3 * dst_stride;

for (loop_cnt = (height >> 2); loop_cnt--;) {
    ((int16_t*)(((uint8_t*)dst) + dst_offset_a))[0] = (int16_t)(((uint8_t*)src)[src_offset_a]);
    ((int16_t*)(((uint8_t*)dst) + dst_offset_b))[0] = (int16_t)(((uint8_t*)src)[src_offset_b]);
    ((int16_t*)(((uint8_t*)dst) + dst_offset_c))[0] = (int16_t)(((uint8_t*)src)[src_offset_c]);
    ((int16_t*)(((uint8_t*)dst) + dst_offset_d))[0] = (int16_t)(((uint8_t*)src)[src_offset_d]);

    src += (4 * src_stride);
    dst += (4 * dst_stride);
}
}
