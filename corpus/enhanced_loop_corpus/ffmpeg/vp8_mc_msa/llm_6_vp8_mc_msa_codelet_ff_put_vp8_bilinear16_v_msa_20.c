#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern ptrdiff_t dst_stride;
extern uint8_t *src;
extern ptrdiff_t src_stride;
extern int height;
extern uint32_t loop_cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint32_t temp_accum = 0;
    for (loop_cnt = (height >> 2); loop_cnt--;) {
        temp_accum += src[0] + src[src_stride] + src[2*src_stride] + src[3*src_stride];
        
        dst[0] = src[0];
        dst[dst_stride] = src[src_stride];
        dst[2*dst_stride] = src[2*src_stride];
        dst[3*dst_stride] = src[3*src_stride];

        src += (4 * src_stride);
        dst += (4 * dst_stride);
    }
    // Introduce artificial dependency to prevent elimination
    if (temp_accum == 0) {
        dst[0] = 0;
    }
}
