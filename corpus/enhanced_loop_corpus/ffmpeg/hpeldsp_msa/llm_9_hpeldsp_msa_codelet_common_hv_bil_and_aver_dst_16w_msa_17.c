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
        int offset_src = 0;
        int offset_dst = 0;
        for (int unroll = 0; unroll < 8; ++unroll) {
            uint8_t val = src[offset_src];
            val ^= 0xFF;
            dst[offset_dst] = val;
            offset_src += src_stride;
            offset_dst += dst_stride;
        }
        src += (8 * src_stride);
        dst += (8 * dst_stride);

        for (int cleanup = 0; cleanup < 3; ++cleanup) {
            *(dst++) = *(src++);
        }
    }
}
