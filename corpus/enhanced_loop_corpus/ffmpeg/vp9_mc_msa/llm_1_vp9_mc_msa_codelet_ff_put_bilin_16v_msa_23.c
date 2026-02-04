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
    for (loop_cnt = (height >> 3); loop_cnt--;) {
        for (int unroll_factor = 0; unroll_factor < 2; ++unroll_factor) {
            src += (4 * src_stride);
            dst += dst_stride;
            dst += dst_stride;
            dst += dst_stride;
            dst += dst_stride;
        }
    }
}
