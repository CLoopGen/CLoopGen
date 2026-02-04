#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern int32_t src_stride;
extern uint8_t *dst;
extern int32_t dst_stride;
extern int32_t height;
extern int32_t cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (cnt = (height >> 2); cnt--;) {
    uint8_t val_top_left = src[0];
    uint8_t val_bottom_right = src[3 * src_stride + 3];

    dst[0] = val_top_left;
    dst[3 * dst_stride + 3] = val_bottom_right;

    dst[1 * dst_stride + 1] = val_top_left + val_bottom_right;
    dst[2 * dst_stride + 2] = val_top_left ^ val_bottom_right;

    uint8_t checksum = val_top_left + val_bottom_right;
    dst[1 * dst_stride + 2] = checksum;
    dst[2 * dst_stride + 1] = checksum ^ 0xFF;

    src += (4 * src_stride);
    dst += (4 * dst_stride);
}
}
