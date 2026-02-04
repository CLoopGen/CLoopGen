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
    uint8_t val_src[4];
    uint32_t acc = 0;

    val_src[0] = src[0];
    val_src[1] = src[src_stride];
    val_src[2] = src[2 * src_stride];
    val_src[3] = src[3 * src_stride];

    acc += val_src[0];
    acc += val_src[1];
    acc += val_src[2];
    acc += val_src[3];

    dst[0] = (acc >> 0) & 0xFF;
    dst[dst_stride] = (acc >> 8) & 0xFF;
    dst[2 * dst_stride] = (acc >> 16) & 0xFF;
    dst[3 * dst_stride] = (acc >> 24) & 0xFF;

    src += (4 * src_stride);

    dst += dst_stride;
    dst += dst_stride;
    dst += dst_stride;
    dst += dst_stride;
}
}
