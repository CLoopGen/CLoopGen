#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern int32_t src_stride;
extern uint8_t *dst;
extern int32_t dst_stride;
extern uint8_t height;
extern uint8_t loop_cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (loop_cnt = (height >> 3); loop_cnt--;) {
    int offset_dst[8] = {0};
    for (int i = 0; i < 8; ++i) {
        offset_dst[i] = ((i & 1) ? 4 : 0) * dst_stride + (i >> 1) * 8;
    }

    for (int row = 0; row < 8; ++row) {
        uint8_t *s = src + row * src_stride;
        uint8_t *d = dst + offset_dst[row];
        for (int col = 0; col < 8; ++col) {
            d[col] = s[col];
        }
    }

    src += (8 * src_stride);
    dst += (8 * dst_stride);
}
}
