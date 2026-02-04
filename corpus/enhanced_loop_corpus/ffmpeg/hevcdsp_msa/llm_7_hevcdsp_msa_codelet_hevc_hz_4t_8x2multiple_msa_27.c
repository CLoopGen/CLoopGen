#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern int32_t src_stride;
extern int16_t *dst;
extern int32_t dst_stride;
extern int32_t height;
extern uint32_t loop_cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint32_t i;
    int16_t *d0, *d1;
    const uint8_t *s0, *s1;
    for (i = 0; i < (height >> 1); ++i) {
        s0 = &src[0];
        s1 = &src[src_stride];
        d0 = &dst[0];
        d1 = &dst[dst_stride];

        d0[0] = (int16_t)s0[0];
        d0[1] = (int16_t)s0[1];
        d1[0] = (int16_t)s1[0];
        d1[1] = (int16_t)s1[1];

        src += (2 * src_stride);
        dst += (2 * dst_stride);
    }
}
