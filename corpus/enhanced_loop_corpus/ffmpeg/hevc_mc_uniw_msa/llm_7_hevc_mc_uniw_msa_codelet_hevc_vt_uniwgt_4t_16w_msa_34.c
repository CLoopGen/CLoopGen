#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern int32_t src_stride;
extern uint8_t *dst;
extern int32_t dst_stride;
extern int32_t height;
extern int32_t loop_cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (loop_cnt = (height >> 2); loop_cnt--;) {
    uint8_t val_top_left, val_top_right, val_bottom_left, val_bottom_right;

    val_top_left = src[0];
    val_top_right = src[15]; 
    val_bottom_left = src[3 * src_stride];
    val_bottom_right = src[3 * src_stride + 15];

    dst[0] = val_bottom_right;
    dst[15] = val_bottom_left;
    dst[3 * dst_stride] = val_top_right;
    dst[3 * dst_stride + 15] = val_top_left;

    uint8_t checksum = val_top_left ^ val_top_right ^ val_bottom_left ^ val_bottom_right;
    dst[4 * dst_stride - 1] = checksum;

    src += (4 * src_stride);
    dst += (4 * dst_stride);
}
}
