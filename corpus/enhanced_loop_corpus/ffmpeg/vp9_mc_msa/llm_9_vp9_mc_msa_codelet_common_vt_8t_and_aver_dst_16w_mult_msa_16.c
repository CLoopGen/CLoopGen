#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern int32_t src_stride;
extern uint8_t *dst;
extern int32_t dst_stride;
extern int32_t height;
extern int32_t width;
extern  uint8_t *src_tmp;
extern uint8_t *dst_tmp;
extern uint32_t loop_cnt;
extern uint32_t cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (cnt = (width >> 5); cnt--;) {
    src_tmp = src;
    dst_tmp = dst;
    for (loop_cnt = (height >> 3); loop_cnt--;) {
        {
            {
                src_tmp += 2 * src_stride;
                dst_tmp += 2 * dst_stride;
            }
            ;
            {
                src_tmp += 4 * src_stride;
                dst_tmp += 4 * dst_stride;
            }
            ;
        }
        ;
        {
            {
                src_tmp += 6 * src_stride;
                dst_tmp += 6 * dst_stride;
            }
            ;
            {
                src_tmp += 8 * src_stride;
                dst_tmp += 8 * dst_stride;
            }
            ;
        }
        ;
        {
            {
                src_tmp += 10 * src_stride;
                dst_tmp += 10 * dst_stride;
            }
            ;
            {
                src_tmp += 12 * src_stride;
                dst_tmp += 12 * dst_stride;
            }
            ;
        }
        ;
        {
            {
                src_tmp += 14 * src_stride;
                dst_tmp += 14 * dst_stride;
            }
            ;
            {
                src_tmp += 16 * src_stride;
                dst_tmp += 16 * dst_stride;
            }
            ;
        }
        ;
        dst_tmp += (8 * dst_stride);
    }
    src += 64;
    dst += 64;
}
}
