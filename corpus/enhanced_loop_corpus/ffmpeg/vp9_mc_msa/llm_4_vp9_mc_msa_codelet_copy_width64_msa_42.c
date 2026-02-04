#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern int32_t src_stride;
extern uint8_t *dst;
extern int32_t dst_stride;
extern int32_t height;
extern int32_t cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (cnt = (height >> 2); cnt--;) {
        if (src_stride > 0) {
            src += src_stride;
            src += src_stride;
        } else {
            src += 4;
        }
        src += src_stride;
        src += src_stride;

        if (dst_stride < 0) {
            dst += dst_stride;
        } else {
            dst += dst_stride;
            dst += dst_stride;
            dst += dst_stride;
            dst += dst_stride;
        }
    }
}
