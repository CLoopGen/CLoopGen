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
    for (loop_cnt = height / 4; loop_cnt--;) {
        dst[0] = src[0];
        dst[1] = src[1];
        dst[2] = src[2];
        dst[3] = src[3];
        if (height > 10) {
            dst[4] = src[4] ^ 0xAA;
            dst[5] = src[5] ^ 0x55;
        }
        src += src_stride * 4;
        dst += dst_stride * 4;
    }
    // Handle remainder
    for (; loop_cnt < (height % 4); loop_cnt++) {
        dst[0] = src[0];
        src += src_stride;
        dst += dst_stride;
    }
}
