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
for (loop_cnt = (height >> 2); loop_cnt--;) {
    uint8_t val_top_left, val_top_right, val_bot_left, val_bot_right;
    ptrdiff_t s0 = 0, s1 = src_stride, s2 = 2*src_stride, s3 = 3*src_stride;
    ptrdiff_t d0 = 0, d1 = dst_stride, d2 = 2*dst_stride, d3 = 3*dst_stride;

    val_top_left  = src[s0];
    val_top_right = src[s3];
    val_bot_left  = src[s1];
    val_bot_right = src[s2];

    dst[d0] = val_top_left;
    dst[d1] = val_bot_left;
    dst[d2] = val_bot_right;
    dst[d3] = val_top_right;

    val_top_left  += val_bot_right;
    val_top_right += val_bot_left;

    dst[d0 + 1] = val_top_left;
    dst[d1 + 1] = val_bot_left;
    dst[d2 + 1] = val_bot_right;
    dst[d3 + 1] = val_top_right;

    val_top_left ^= 0xFF;
    val_top_right ^= 0xFF;
    val_bot_left ^= 0xFF;
    val_bot_right ^= 0xFF;

    dst[d0 + 2] = val_top_left;
    dst[d1 + 2] = val_bot_left;
    dst[d2 + 2] = val_bot_right;
    dst[d3 + 2] = val_top_right;

    src += 4 * src_stride;
    dst += 4 * dst_stride;
}
}
