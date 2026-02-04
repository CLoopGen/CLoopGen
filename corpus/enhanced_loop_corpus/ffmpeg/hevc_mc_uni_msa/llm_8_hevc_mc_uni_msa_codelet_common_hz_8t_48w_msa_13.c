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
        src += src_stride;
        dst += dst_stride;
        uint32_t temp = (uint32_t)(src[0]) * 2 + 5;
        temp ^= 0xAA;
        dst[0] = (uint8_t)(temp & 0xFF);
        src += src_stride;
        dst += dst_stride;
        if (loop_cnt % 3 == 0) {
            src -= 1;
            dst -= 1;
        }
    }
}
