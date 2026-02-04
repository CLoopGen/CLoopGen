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
    uint8_t val_top, val_mid, val_bot;
    uint8_t acc = 0;

    val_top = src[0];
    acc += val_top;

    dst[0] = acc;
    
    val_mid = src[4 * src_stride];
    acc += val_mid;
    dst[4 * dst_stride] = acc;

    val_bot = src[7 * src_stride];
    acc += val_bot;
    dst[7 * dst_stride] = acc;

    acc = val_top ^ val_mid ^ val_bot;
    dst[dst_stride] = acc;
    dst[2 * dst_stride] = acc << 1;
    dst[3 * dst_stride] = acc >> 1;

    acc ^= src[1 * src_stride];
    dst[5 * dst_stride] = acc;
    acc ^= src[6 * src_stride];
    dst[6 * dst_stride] = acc;

    acc = src[2 * src_stride] + src[5 * src_stride];
    dst[2 * dst_stride] = acc;
    dst[3 * dst_stride] += acc; 

    src += (8 * src_stride);

    dst += dst_stride;
    dst += dst_stride;
    dst += dst_stride;
    dst += dst_stride;
    dst += dst_stride;
    dst += dst_stride;
    dst += dst_stride;
    dst += dst_stride;
}
}
