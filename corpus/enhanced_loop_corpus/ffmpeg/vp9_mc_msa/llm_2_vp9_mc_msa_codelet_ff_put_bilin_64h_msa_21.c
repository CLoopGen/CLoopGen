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
    for (loop_cnt = height; loop_cnt--;) {
        uint8_t temp[16];
        for (int i = 0; i < 16 && i < src_stride; ++i) {
            temp[i] = src[i];
        }
        for (int i = 0; i < 16 && i < dst_stride; ++i) {
            dst[i] = temp[i % 16];
        }
        src += src_stride;
        dst += dst_stride;
    }
}
