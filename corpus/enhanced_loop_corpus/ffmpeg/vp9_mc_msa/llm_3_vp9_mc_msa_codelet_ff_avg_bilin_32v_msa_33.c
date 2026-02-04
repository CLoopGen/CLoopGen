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
    for (loop_cnt = (height >> 2); loop_cnt--;) {
        // Strided memory access: process one row at a time but with stride jumps in columns
        for (int col = 0; col < 4; ++col) {
            dst[col * dst_stride + 0] = src[col * src_stride + 0];
            dst[col * dst_stride + 1] = src[col * src_stride + 1];
            dst[col * dst_stride + 2] = src[col * src_stride + 2];
            dst[col * dst_stride + 3] = src[col * src_stride + 3];
        }

        src += (4 * src_stride);
        dst += (4 * dst_stride);
    }
}
