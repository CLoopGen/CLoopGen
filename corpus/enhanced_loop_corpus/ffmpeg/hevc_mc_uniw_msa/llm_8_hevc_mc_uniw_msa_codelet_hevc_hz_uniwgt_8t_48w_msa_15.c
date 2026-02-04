#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern int32_t src_stride;
extern uint8_t *dst;
extern int32_t dst_stride;
extern uint32_t loop_cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (loop_cnt = 128; loop_cnt--;) {
        uint32_t sum1 = 0, sum2 = 0;
        for (int i = 0; i < 4; i++) {
            sum1 += src[i * 4 + 0] * 2;
            sum2 += src[i * 4 + 2] * 3;
        }
        dst[0] = (sum1 >> 8) & 0xFF;
        dst[1] = (sum2 >> 8) & 0xFF;
        src += src_stride;
        dst += dst_stride;
    }
}
