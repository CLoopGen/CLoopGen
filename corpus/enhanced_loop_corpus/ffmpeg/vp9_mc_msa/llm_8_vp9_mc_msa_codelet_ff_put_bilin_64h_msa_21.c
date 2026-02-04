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
        uint32_t temp = 0;
        for (int i = 0; i < 4; ++i) {
            temp += src[i] * 3;
            dst[i] = (uint8_t)(temp & 0xFF);
        }
        src += src_stride;
        dst += dst_stride;
    }
}
