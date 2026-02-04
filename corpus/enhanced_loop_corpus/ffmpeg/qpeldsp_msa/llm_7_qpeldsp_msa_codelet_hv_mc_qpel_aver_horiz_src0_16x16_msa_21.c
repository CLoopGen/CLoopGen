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
    uint8_t accumulator = 0;
    uint8_t *local_src = src;
    uint8_t *local_dst = dst;
    int32_t i;

    for (loop_count = (height >> 2); loop_count--;) {
        accumulator = 0;
        for (i = 0; i < 4; ++i) {
            accumulator += local_src[i * src_stride];
        }

        for (i = 0; i < 4; ++i) {
            local_dst[i * dst_stride] = accumulator;
        }

        local_src += (4 * src_stride);
        local_dst += (4 * dst_stride);
    }

    src = local_src;
    dst = local_dst;
}
