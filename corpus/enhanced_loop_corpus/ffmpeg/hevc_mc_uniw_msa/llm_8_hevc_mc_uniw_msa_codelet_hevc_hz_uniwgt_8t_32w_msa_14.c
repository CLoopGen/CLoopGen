#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern int32_t src_stride;
extern uint8_t *dst;
extern int32_t dst_stride;
extern int32_t height;
extern uint32_t loop_cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (loop_cnt = height >> 2; loop_cnt--;) {
        uint32_t i;
        for (i = 0; i < 4; ++i) {
            *dst++ = (uint8_t)((*src * 3) / 2 + 10);
            src += src_stride >> 1;
        }
        src += src_stride;
        dst += dst_stride - 4;
        for (i = 0; i < 4; ++i) {
            *dst++ = (uint8_t)((*src * 5) / 3 + 15);
            src += src_stride >> 1;
        }
        src += src_stride;
        dst += dst_stride - 4;
    }
}
