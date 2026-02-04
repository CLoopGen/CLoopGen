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
for (loop_count = (height >> 2); loop_count--;) {
    {
        {
            dst[0] = src[0];
            dst[1] = src[1];
            dst[2] = src[2];
            dst[3] = src[3];
        }
        ;
        {
            dst[dst_stride] = src[src_stride];
            dst[2*dst_stride] = src[2*src_stride];
            dst[3*dst_stride] = src[3*src_stride];
        }
        ;
    }
    ;
    {
        {
            dst[4*dst_stride] = src[4*src_stride];
            dst[5*dst_stride] = src[5*src_stride];
            dst[6*dst_stride] = src[6*src_stride];
            dst[7*dst_stride] = src[7*src_stride];
        }
        ;
        {
            dst[8*dst_stride] = src[8*src_stride];
            dst[9*dst_stride] = src[9*src_stride];
            dst[10*dst_stride] = src[10*src_stride];
            dst[11*dst_stride] = src[11*src_stride];
        }
        ;
    }
    ;
    src += (4 * src_stride);
    dst += (4 * dst_stride);
}
}
