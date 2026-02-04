#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern int32_t src_stride;
extern int16_t *dst;
extern int32_t dst_stride;
extern int32_t height;
extern uint32_t loop_cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (loop_cnt = (height >> 1); loop_cnt--;) {
        uint32_t step = (loop_cnt & 1) ? 1 : 2;
        if (step == 2) {
            src += src_stride;
            {
            }
            ;
            src += src_stride;
        } else {
            src += src_stride;
        }
        {
        }
        ;
        {
        }
        ;
        if ((loop_cnt % 3) == 0) {
            dst += dst_stride;
        }
        dst += dst_stride;
    }
}
