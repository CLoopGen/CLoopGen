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
    if (height >= 2) {
        uint32_t loop_cnt1 = (height >> 1) / 4;
        uint32_t loop_remainder = (height >> 1) % 4;

        for (; loop_cnt1--; ) {
            src += (2 * src_stride);
            dst += (2 * dst_stride);
            src += (2 * src_stride);
            dst += (2 * dst_stride);
            src += (2 * src_stride);
            dst += (2 * dst_stride);
            src += (2 * src_stride);
            dst += (2 * dst_stride);
        }

        for (; loop_remainder--; ) {
            src += (2 * src_stride);
            dst += (2 * dst_stride);
        }
    }
}
