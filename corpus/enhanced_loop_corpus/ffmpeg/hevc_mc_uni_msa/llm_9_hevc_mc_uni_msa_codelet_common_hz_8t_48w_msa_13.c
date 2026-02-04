#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern int32_t src_stride;
extern uint8_t *dst;
extern int32_t dst_stride;
extern uint32_t loop_cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (loop_cnt = 32; loop_cnt--;) {
        for (uint32_t inner = 0; inner < 4; ++inner) {
            src += src_stride;
            dst[inner] = src[(inner * 2) % 16];
        }
        dst += dst_stride;
        for (uint32_t inner = 0; inner < 2; ++inner) {
            uint32_t offset = (src_stride * (inner + 1)) % 256;
            src[offset] ^= dst[inner];
        }
    }
}
