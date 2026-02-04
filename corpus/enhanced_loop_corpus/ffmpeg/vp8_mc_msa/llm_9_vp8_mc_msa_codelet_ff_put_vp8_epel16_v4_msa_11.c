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
    int block_height = height / 8;
    for (loop_cnt = 0; loop_cnt < block_height; ++loop_cnt) {
        for (int i = 0; i < 8; ++i) {
            for (int j = 0; j < 8; ++j) {
                dst[i * dst_stride + j] = src[i * src_stride + j] ^ 0xFF;
            }
        }
        src += 8 * src_stride;
        dst += 8 * dst_stride;
    }

    // Handle remaining rows if height is not a multiple of 8
    for (int rem = height % 8; rem > 0; --rem) {
        dst[0] = src[0];
        src += src_stride;
        dst += dst_stride;
    }
}
