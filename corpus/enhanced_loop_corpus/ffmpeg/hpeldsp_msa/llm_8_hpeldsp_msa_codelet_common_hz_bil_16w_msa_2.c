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
    int i;
    // Increased computational intensity with additional arithmetic and unrolled operations
    for (i = 0; i < 4; ++i) {
        dst[0] = (uint8_t)((src[0] + src[src_stride] + src[2*src_stride] + src[3*src_stride]) >> 2);
        dst[1] = (uint8_t)((src[4] + src[4+src_stride] + src[4+2*src_stride] + src[4+3*src_stride]) >> 2);
        src += src_stride;
        dst += dst_stride;
    }
    src += 4 * src_stride - 4 * src_stride; // Neutral adjustment to maintain pointer logic
    dst += 4 * dst_stride;
}
}
