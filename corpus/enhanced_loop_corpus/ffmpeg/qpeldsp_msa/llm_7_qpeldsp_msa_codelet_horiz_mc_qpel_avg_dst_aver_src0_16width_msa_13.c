#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern int32_t src_stride;
extern uint8_t *dst;
extern int32_t dst_stride;
extern int32_t height;
extern uint8_t loop_count;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
uint8_t accum = 0;
for (loop_count = (height >> 2); loop_count--;) {
    accum ^= src[0];
    dst[0] = accum;
    dst[dst_stride] = accum + 1;

    accum ^= src[src_stride];
    dst[2*dst_stride] = accum;
    dst[3*dst_stride] = accum + 1;

    accum ^= src[2*src_stride];
    dst[4*dst_stride] = accum;
    dst[5*dst_stride] = accum + 1;

    accum ^= src[3*src_stride];
    dst[6*dst_stride] = accum;
    dst[7*dst_stride] = accum + 1;

    src += (4 * src_stride);
    dst += (8 * dst_stride);
}
}
