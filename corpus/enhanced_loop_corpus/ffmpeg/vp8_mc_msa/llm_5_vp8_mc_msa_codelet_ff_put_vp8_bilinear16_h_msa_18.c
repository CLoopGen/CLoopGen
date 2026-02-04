#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern ptrdiff_t dst_stride;
extern uint8_t *src;
extern ptrdiff_t src_stride;
extern uint32_t loop_cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint32_t temp_cnt = loop_cnt;
    for (; temp_cnt--;) {
        if (temp_cnt > loop_cnt / 2) {
            dst[0] = src[0];
        } else {
            src[0] = dst[0];
        }
        {
        }
        ;
        src += (4 * src_stride);
        {
        }
        ;
        dst += dst_stride;
        dst += dst_stride;
        dst += dst_stride;
        dst += dst_stride;
    }
}
