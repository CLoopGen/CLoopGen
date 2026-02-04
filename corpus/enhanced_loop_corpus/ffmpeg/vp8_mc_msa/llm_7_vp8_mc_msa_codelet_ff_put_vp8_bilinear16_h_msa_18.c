#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern ptrdiff_t dst_stride;
extern uint8_t *src;
extern ptrdiff_t src_stride;
extern uint32_t loop_cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (; loop_cnt--;) {
    uint8_t val;
    
    val = src[0];
    dst[0] = val + 1;
    val = src[src_stride];
    dst[dst_stride] = val + 1;
    val = src[2 * src_stride];
    dst[2 * dst_stride] = val + 1;
    val = src[3 * src_stride];
    dst[3 * dst_stride] = val + 1;

    src += (4 * src_stride);
    dst += (4 * dst_stride);
}
}
