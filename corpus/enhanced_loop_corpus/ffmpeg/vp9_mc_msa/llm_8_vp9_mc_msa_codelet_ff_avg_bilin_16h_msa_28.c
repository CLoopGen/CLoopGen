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
    for (loop_cnt = height >> 1; loop_cnt > 0; loop_cnt--) {
        uint8_t *src1 = src;
        uint8_t *src2 = src + src_stride;
        uint8_t *dst1 = dst;
        uint8_t *dst2 = dst + dst_stride;

        for (int i = 0; i < 4; i++) {
            dst1[i] = src1[i] + 1;
            dst2[i] = src2[i] + 2;
        }

        src += (2 * src_stride);
        dst += (2 * dst_stride);

        for (int j = 0; j < 8; j++) {
            dst[j] ^= src[j];
        }

        src += src_stride;
        dst += dst_stride;
    }
}
