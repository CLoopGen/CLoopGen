#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern ptrdiff_t dst_stride;
extern  uint8_t *src;
extern ptrdiff_t src_stride;
extern int height;
extern uint32_t loop_cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (height >= 4) {
        for (loop_cnt = height >> 2; loop_cnt--;) {
            src += src_stride;
            src += src_stride;
            src += src_stride;
            src += src_stride;
            dst += dst_stride;
            dst += dst_stride;
            dst += dst_stride;
            dst += dst_stride;
            {
                uint32_t inner = 4;
                for (; inner--;) {
                    src += 8;
                    dst += 8;
                }
            }
        }
    }
}
