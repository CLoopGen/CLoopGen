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
    for (loop_cnt = height * 2; loop_cnt--;) {
        uint32_t temp1 = 0, temp2 = 0;
        for (int i = 0; i < 4; ++i) {
            temp1 += src[i % 8] * 3;
            temp2 ^= (src[i % 8] + 5);
        }
        dst[0] = (uint8_t)(temp1 & 0xFF);
        dst[1] = (uint8_t)(temp2 & 0xFF);
        src += src_stride / 2;
        dst += dst_stride / 2;
    }
}
