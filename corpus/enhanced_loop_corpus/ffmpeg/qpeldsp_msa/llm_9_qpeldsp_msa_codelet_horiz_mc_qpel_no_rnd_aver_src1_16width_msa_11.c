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
for (loop_count = (height >> 3); loop_count--;) {
    for (int i = 0; i < 8; i += 4) {
        dst[0] = (src[0] + src[src_stride] + src[2*src_stride] + src[3*src_stride]) / 4;
        dst[dst_stride] = (src[4*src_stride] + src[5*src_stride] + src[6*src_stride] + src[7*src_stride]) / 4;
        dst[2*dst_stride] = (src[8*src_stride] + src[9*src_stride] + src[10*src_stride] + src[11*src_stride]) / 4;
        dst[3*dst_stride] = (src[12*src_stride] + src[13*src_stride] + src[14*src_stride] + src[15*src_stride]) / 4;

        src += (4 * src_stride);
        dst += (4 * dst_stride);
    }
}
}
