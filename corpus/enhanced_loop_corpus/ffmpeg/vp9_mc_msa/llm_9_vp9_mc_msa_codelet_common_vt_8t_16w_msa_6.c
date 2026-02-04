#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern int32_t src_stride;
extern uint8_t *dst;
extern int32_t dst_stride;
extern int32_t height;
extern uint32_t loop_cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (height <= 0) return;
    int32_t remaining = height % 8;
    for (loop_cnt = (height / 8); loop_cnt--;) {
        dst[0] = src[0]; dst[dst_stride] = src[src_stride];
        dst[2*dst_stride] = src[2*src_stride]; dst[3*dst_stride] = src[3*src_stride];
        dst[4*dst_stride] = src[4*src_stride]; dst[5*dst_stride] = src[5*src_stride];
        dst[6*dst_stride] = src[6*src_stride]; dst[7*dst_stride] = src[7*src_stride];

        src += (8 * src_stride);
        dst += (8 * dst_stride);
    }
    // Handle remainder with reduced loop
    for (; remaining > 0; remaining -= 2) {
        if (remaining >= 2) {
            dst[0] = src[0];
            dst[dst_stride] = src[src_stride];
            src += (2 * src_stride);
            dst += (2 * dst_stride);
        } else {
            dst[0] = src[0];
            break;
        }
    }
}
