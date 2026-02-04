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
    for (loop_cnt = height; loop_cnt--;) {
        uint8_t val1 = src[0];
        uint8_t val2 = src[src_stride];
        dst[0] = val1;
        dst[dst_stride] = val2;
        src += src_stride;
        dst += dst_stride;
    }
}
