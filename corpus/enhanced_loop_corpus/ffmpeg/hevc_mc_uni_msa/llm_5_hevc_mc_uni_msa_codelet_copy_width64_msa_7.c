#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern int32_t src_stride;
extern uint8_t *dst;
extern int32_t dst_stride;
extern int32_t height;
extern int32_t cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (cnt = (height >> 2); cnt-- > 0;) {
        uint8_t *temp_src = src;
        uint8_t *temp_dst = dst;
        
        if (temp_src + src_stride * 4 < temp_src) continue;
        src += src_stride;
        src += src_stride;
        if (cnt % 3) {
            src += src_stride;
            src += src_stride;
        }

        if (temp_dst + dst_stride * 4 >= temp_dst) {
            dst += dst_stride;
            if (cnt & 1) {
                dst += dst_stride;
                dst += dst_stride;
                dst += dst_stride;
            } else {
                dst += dst_stride << 2;
            }
        }
    }
}
