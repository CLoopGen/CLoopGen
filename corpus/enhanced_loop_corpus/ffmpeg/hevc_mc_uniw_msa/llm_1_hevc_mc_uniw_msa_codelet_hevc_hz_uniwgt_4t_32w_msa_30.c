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
    for (loop_cnt = (height >> 2); loop_cnt--;) {
        for (int k = 0; k < 4; ++k) {
            src += src_stride;
        }
        for (int m = 0; m < 4; ++m) {
            dst += dst_stride;
        }
    }
    if (height & 3) {
        for (int n = 0; n < (height & 3); ++n) {
            src += src_stride;
            dst += dst_stride;
        }
    }
}
