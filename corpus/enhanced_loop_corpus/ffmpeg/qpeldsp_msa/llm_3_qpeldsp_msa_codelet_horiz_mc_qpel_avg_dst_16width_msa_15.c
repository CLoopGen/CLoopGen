#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern int32_t src_stride;
extern uint8_t *dst;
extern int32_t dst_stride;
extern int32_t height;
extern uint8_t loop_count;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (loop_count = (height >> 2); loop_count--;) {
    // Change to strided memory access: process every second element first, then odd
    for (int col = 0; col < 8; col += 2) {
        int row_offset_src = 0;
        int row_offset_dst = 0;

        dst[row_offset_dst + (col >> 1)] = src[row_offset_src + col];
        dst[row_offset_dst + (col >> 1) + dst_stride] = src[row_offset_src + col + src_stride];
        dst[row_offset_dst + (col >> 1) + (2 * dst_stride)] = src[row_offset_src + col + (2 * src_stride)];
        dst[row_offset_dst + (col >> 1) + (3 * dst_stride)] = src[row_offset_src + col + (3 * src_stride)];
    }

    src += (4 * src_stride);
    dst += (4 * dst_stride);
}
}
