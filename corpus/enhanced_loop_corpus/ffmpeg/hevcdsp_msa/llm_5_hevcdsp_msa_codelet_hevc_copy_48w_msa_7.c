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
    for (loop_cnt = (height >> 2); loop_cnt--;) {
        int32_t temp_src_stride = src_stride;
        int32_t temp_dst_stride = dst_stride;

        src += temp_src_stride;
        {
            if (temp_src_stride > 8) {
                src += temp_src_stride;
            }
        }
        src += temp_src_stride;
        if (temp_src_stride < 16) {
            src += temp_src_stride;
        }

        dst += temp_dst_stride;
        {
            if (temp_dst_stride > 0) {
                dst += temp_dst_stride;
            }
        }
        {
            dst += temp_dst_stride;
        }
        if (temp_dst_stride <= 32) {
            dst += temp_dst_stride;
        }

        {
            {
                {
                }
                ;
                {
                }
                ;
            }
            ;
            {
            }
            ;
        }
    }
}
