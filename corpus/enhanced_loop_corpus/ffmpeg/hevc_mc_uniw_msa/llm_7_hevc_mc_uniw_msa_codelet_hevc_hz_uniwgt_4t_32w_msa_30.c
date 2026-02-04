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
for (loop_cnt = (height >> 1); loop_cnt--;) {
    uint8_t val_top = src[0];
    uint8_t val_bottom = src[src_stride * 2 - 1];

    dst[0] = val_top ^ 0x55;
    dst[dst_stride] = val_bottom ^ 0xAA;

    src += src_stride;
    {
        uint8_t mid_val = src[src_stride / 2];
        dst[1] = mid_val;
    }
    src += src_stride;

    dst += dst_stride;
    {
        uint8_t adj_val = src[-1];
        dst[1] = adj_val;
    }
    dst += dst_stride;

    val_top = val_bottom ^ val_top;
    dst[-dst_stride] ^= val_top;
}
}
