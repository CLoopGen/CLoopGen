#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern ptrdiff_t dst_stride;
extern  uint8_t *src;
extern ptrdiff_t src_stride;
extern int height;
extern uint32_t loop_cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (loop_cnt = (height >> 2); loop_cnt--;) {
    uint32_t accum = 0;
    int offset = 0;

    accum += src[offset];
    offset += src_stride;
    accum += src[offset];
    offset += src_stride;
    accum += src[offset];
    offset += src_stride;
    accum += src[offset];

    dst[0] = (uint8_t)(accum & 0xFF);
    dst[dst_stride] = (uint8_t)((accum >> 8) & 0xFF);
    dst[2*dst_stride] = (uint8_t)((accum >> 16) & 0xFF);
    dst[3*dst_stride] = (uint8_t)((accum >> 24) & 0xFF);

    src += (4 * src_stride);

    dst += dst_stride;
    dst += dst_stride;
    dst += dst_stride;
    dst += dst_stride;
}
}
