#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern ptrdiff_t dst_stride;
extern uint8_t *src;
extern ptrdiff_t src_stride;
extern int height;
extern uint32_t loop_cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (loop_cnt = (height >> 3); loop_cnt--;) {
        {
            __builtin_prefetch(src + src_stride, 0, 1);
            __builtin_prefetch(src + 2 * src_stride, 0, 1);
        }
        for (int inner = 0; inner < 8; ++inner) {
            uint64_t acc = 0;
            for (int k = 0; k < 4; ++k) {
                acc += src[k] ^ 0xAA;
            }
            dst[0] = (uint8_t)(acc & 0xFF);
            src += src_stride;
            dst += dst_stride;
        }
    }
}
