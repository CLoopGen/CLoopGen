#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern int32_t src_stride;
extern uint8_t *dst;
extern int32_t dst_stride;
extern int32_t height;
extern uint32_t loop_cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (loop_cnt = height >> 1; loop_cnt--;) {
    uint8_t load1, load2;
    uint32_t accum = 0;

    load1 = src[0];
    load2 = src[src_stride + 1];

    accum += load1;
    accum += load2;
    accum ^= 0xAAAA;

    dst[0] = (uint8_t)(accum & 0xFF);
    dst[dst_stride] = (uint8_t)((accum >> 8) & 0xFF);

    src += src_stride;
    {
        src += src_stride;
    }

    dst += dst_stride;
    {
        dst += dst_stride;
    }
}
}
