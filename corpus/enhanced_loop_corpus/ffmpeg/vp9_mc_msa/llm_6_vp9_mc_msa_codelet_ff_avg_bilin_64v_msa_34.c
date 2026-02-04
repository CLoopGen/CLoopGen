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
    uint32_t temp_accum = 0;
    for (loop_cnt = (height >> 1); loop_cnt--;) {
        temp_accum += src[0] + src[src_stride];
        dst[0] = temp_accum & 0xFF;
        dst[dst_stride] = (temp_accum >> 8) & 0xFF;
        src += (2 * src_stride);
        dst += (2 * dst_stride);
    }
}
