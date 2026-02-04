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
const int32_t *idx_src = (const int32_t*)src; // Assume stride allows indexing
const int32_t *idx_dst = (const int32_t*)dst;
for (loop_cnt = height; loop_cnt--;) {
    int32_t offset = (loop_cnt & 7) * 4; // Simulate indirect access pattern
    uint8_t val = *(uint8_t*)((char*)idx_src + offset);
    ((int16_t*)idx_dst)[offset / 2] = (int16_t)val;
    src += src_stride;
    dst += dst_stride;
}
}
