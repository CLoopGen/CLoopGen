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
    uint8_t temp1 = src[0];
    uint8_t temp2 = src[src_stride];
    uint8_t temp3 = src[2 * src_stride];
    uint8_t temp4 = src[3 * src_stride];

    dst[0] = temp1;
    dst[dst_stride] = temp2;
    dst[2 * dst_stride] = temp3;
    dst[3 * dst_stride] = temp4;

    src += (4 * src_stride);
    dst += (4 * dst_stride);
}
}
