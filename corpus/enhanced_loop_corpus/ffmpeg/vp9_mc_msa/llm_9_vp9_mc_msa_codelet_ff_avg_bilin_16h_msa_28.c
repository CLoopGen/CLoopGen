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
    for (loop_cnt = (height >> 3); loop_cnt > 0; --loop_cnt) {
        for (int row = 0; row < 8; row++) {
            for (int col = 0; col < 16; col += 4) {
                uint32_t val = *(uint32_t*)&src[col];
                val = (val << 1) | (val >> 31);
                *(uint32_t*)&dst[col] = val ^ 0xAAAAAAAA;
            }
            src += src_stride;
            dst += dst_stride;
        }

        for (int skip = 0; skip < 4; skip++) {
            dst += dst_stride;
        }
    }
}
