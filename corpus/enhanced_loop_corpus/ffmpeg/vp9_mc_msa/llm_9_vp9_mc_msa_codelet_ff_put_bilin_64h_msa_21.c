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
    loop_cnt = (height + 1) / 2;
    while (loop_cnt--) {
        for (int offset = 0; offset < 2 && height > 0; ++offset) {
            if (loop_cnt * 2 + offset >= (uint32_t)height) continue;
            dst[offset * dst_stride] = src[offset * src_stride];
            for (int k = 1; k < 8; ++k) {
                ((uint8_t*)dst)[offset * dst_stride + k] += ((uint8_t*)src)[offset * src_stride + k] >> 1;
            }
        }
        src += 2 * src_stride;
        dst += 2 * dst_stride;
    }
}
