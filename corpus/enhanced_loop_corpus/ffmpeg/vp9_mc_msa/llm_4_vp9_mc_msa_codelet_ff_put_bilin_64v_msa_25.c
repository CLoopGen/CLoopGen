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
    for (loop_cnt = (height >> 1); loop_cnt--;) {
        if (src_stride > 0) {
            src += (2 * src_stride);
        }
        if (dst_stride > 0) {
            dst += (2 * dst_stride);
        }
    }
}
