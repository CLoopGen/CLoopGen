#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern int32_t src_stride;
extern uint8_t *dst;
extern int32_t dst_stride;
extern int32_t height;
extern int32_t width;
extern int32_t cnt;
extern int32_t loop_cnt;
extern uint8_t *src_tmp;
extern uint8_t *dst_tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (cnt = (width >> 4); cnt--;) {
    src_tmp = src;
    dst_tmp = dst;
    uint8_t accumulator = 0;
    for (loop_cnt = (height >> 3); loop_cnt--;) {
        {
            {
                accumulator ^= src_tmp[0];
                dst_tmp[0] = accumulator;
            }
            ;
            {
                accumulator ^= src_tmp[src_stride];
                dst_tmp[dst_stride] = accumulator;
            }
            ;
        }
        ;
        {
            {
                accumulator ^= src_tmp[2*src_stride];
                dst_tmp[2*dst_stride] = accumulator;
            }
            ;
            {
                accumulator ^= src_tmp[3*src_stride];
                dst_tmp[3*dst_stride] = accumulator;
            }
            ;
        }
        ;
        src_tmp += (8 * src_stride);
        {
            {
                accumulator ^= src_tmp[0];
                dst_tmp[4*dst_stride] = accumulator;
            }
            ;
            {
                accumulator ^= src_tmp[src_stride];
                dst_tmp[5*dst_stride] = accumulator;
            }
            ;
        }
        ;
        {
            {
                accumulator ^= src_tmp[2*src_stride];
                dst_tmp[6*dst_stride] = accumulator;
            }
            ;
            {
                accumulator ^= src_tmp[3*src_stride];
                dst_tmp[7*dst_stride] = accumulator;
            }
            ;
        }
        ;
        dst_tmp += (8 * dst_stride);
    }
    src += 16;
    dst += 16;
}
}
