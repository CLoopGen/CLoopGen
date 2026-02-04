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
for (loop_cnt = (height >> 3); loop_cnt--;) {
    uint8_t aggregate = 0;
    for (int offset = 7; offset >= 0; --offset) {
        uint8_t val = src[offset * src_stride];
        aggregate ^= val;
        dst[offset * dst_stride] = val + (aggregate << 1);
    }
    dst[0 * dst_stride] = aggregate; 
    for (int offset = 1; offset < 8; ++offset) {
        dst[offset * dst_stride] += dst[(offset - 1) * dst_stride]; 
    }
    src += (8 * src_stride);
    dst += (8 * dst_stride);
}
}
