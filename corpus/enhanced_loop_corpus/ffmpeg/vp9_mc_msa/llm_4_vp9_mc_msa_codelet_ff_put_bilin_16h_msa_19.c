#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern ptrdiff_t dst_stride;
extern  uint8_t *src;
extern ptrdiff_t src_stride;
extern uint32_t loop_cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint32_t i = 0;
    for (; loop_cnt--;) {
        if (i < 4) {
            src += src_stride;
            i++;
        } else {
            src += (3 * src_stride);
            i = 0;
        }
        dst += dst_stride;
        dst += dst_stride;
        dst += dst_stride;
        dst += dst_stride;
    }
}
