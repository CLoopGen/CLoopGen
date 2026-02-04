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
    for (loop_cnt = height; loop_cnt > 0; loop_cnt -= 2) {
        src += src_stride << 1;
        dst += dst_stride << 1;
        if (loop_cnt < 4) break;
    }
}
