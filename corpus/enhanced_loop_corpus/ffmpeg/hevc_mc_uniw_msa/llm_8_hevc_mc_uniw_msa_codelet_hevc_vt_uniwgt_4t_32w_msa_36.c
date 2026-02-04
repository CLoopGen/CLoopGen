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
    for (loop_cnt = height; loop_cnt--;) {
        uint8_t val1, val2;
        uint32_t sum = 0;

        val1 = src[0];
        val2 = src[src_stride];
        sum += val1 + val2;
        dst[0] = (uint8_t)(sum >> 1);

        val1 = src[1];
        val2 = src[src_stride + 1];
        sum += val1 + val2;
        dst[1] = (uint8_t)(sum >> 2);

        src += src_stride;
        dst += dst_stride;
    }
}
