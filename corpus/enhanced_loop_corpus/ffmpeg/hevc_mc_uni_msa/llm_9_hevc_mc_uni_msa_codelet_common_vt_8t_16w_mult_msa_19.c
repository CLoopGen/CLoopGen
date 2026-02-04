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
extern uint8_t *src_tmp;
extern uint8_t *dst_tmp;
extern uint32_t loop_cnt;
extern uint32_t cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (cnt = (width >> 4); cnt--;) {
    src_tmp = src;
    dst_tmp = dst;
    for (loop_cnt = height; loop_cnt--;) {
        {
            {
                dst_tmp[0] = src_tmp[0];
                dst_tmp[1] = src_tmp[1];
                dst_tmp[2] = src_tmp[2];
                dst_tmp[3] = src_tmp[3];
            }
            ;
            {
                dst_tmp[4] = src_tmp[4];
                dst_tmp[5] = src_tmp[5];
                dst_tmp[6] = src_tmp[6];
                dst_tmp[7] = src_tmp[7];
            }
            ;
        }
        ;
        src_tmp += src_stride;
        dst_tmp += dst_stride;
        {
            {
                dst_tmp[0] = src_tmp[0];
                dst_tmp[1] = src_tmp[1];
                dst_tmp[2] = src_tmp[2];
                dst_tmp[3] = src_tmp[3];
            }
            ;
            {
                dst_tmp[4] = src_tmp[4];
                dst_tmp[5] = src_tmp[5];
                dst_tmp[6] = src_tmp[6];
                dst_tmp[7] = src_tmp[7];
            }
            ;
        }
        ;
        src_tmp += src_stride;
        dst_tmp += dst_stride;
    }
    src += 16;
    dst += 16;
}
}
