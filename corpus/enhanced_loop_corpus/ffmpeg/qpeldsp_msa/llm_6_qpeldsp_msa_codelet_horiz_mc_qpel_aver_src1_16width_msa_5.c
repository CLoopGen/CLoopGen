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
    uint8_t temp[4];
    for (loop_count = (height >> 2); loop_count--;) {
        temp[0] = src[0];
        temp[1] = src[src_stride];
        temp[2] = src[2 * src_stride];
        temp[3] = src[3 * src_stride];

        dst[0] = temp[0] + 1;
        dst[dst_stride] = temp[1] + 1;
        dst[2 * dst_stride] = temp[2] + 1;
        dst[3 * dst_stride] = temp[3] + 1;

        src += (4 * src_stride);
        dst += (4 * dst_stride);
    }
}
