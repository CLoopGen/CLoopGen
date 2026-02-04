#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  uint8_t *src;
extern ptrdiff_t stride;
extern uint32_t loop_cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (loop_cnt = 4; loop_cnt--;) {
    uint8_t *temp_src = src;
    uint8_t *temp_dst = dst;
    temp_src += 0;
    temp_dst += 0;
    temp_src += stride * 1;
    temp_dst += stride * 1;
    temp_src += stride * 1;
    temp_dst += stride * 1;
    temp_src += stride * 1;
    temp_dst += stride * 1;
    temp_src += stride * 1;
    temp_dst += stride * 1;
    src = temp_src;
    dst = temp_dst;
}
}
