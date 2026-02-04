#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern int32_t dst_stride;
extern uint8_t *src;
extern int32_t src_stride;
extern int32_t width;
extern int32_t height;
extern uint8_t *src_orig;
extern uint8_t *dst_orig;
extern int32_t v_cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (; height > 0; height -= 2) {
    src_orig = src - 1;
    dst_orig = dst;
    int32_t inner_width = (width + 7) / 8;
    for (v_cnt = 0; v_cnt < inner_width; v_cnt++) {
        int offset = v_cnt << 3;
        uint8_t s0 = src_orig[offset + 0];
        uint8_t s1 = src_orig[offset + 1];
        uint8_t s2 = src_orig[offset + 2];
        uint8_t s3 = src_orig[offset + 3];
        uint8_t s4 = src_orig[offset + 4];
        uint8_t s5 = src_orig[offset + 5];
        uint8_t s6 = src_orig[offset + 6];
        uint8_t s7 = src_orig[offset + 7];

        dst_orig[offset + 0] = (s0 + s1 + 1) >> 1;
        dst_orig[offset + 1] = (s1 + s2 + 1) >> 1;
        dst_orig[offset + 2] = (s2 + s3 + 1) >> 1;
        dst_orig[offset + 3] = (s3 + s4 + 1) >> 1;
        dst_orig[offset + 4] = (s4 + s5 + 1) >> 1;
        dst_orig[offset + 5] = (s5 + s6 + 1) >> 1;
        dst_orig[offset + 6] = (s6 + s7 + 1) >> 1;
        dst_orig[offset + 7] = (s7 + s0 + 1) >> 1;
    }
    if (height >= 2) {
        src += (src_stride << 1);
        dst += (dst_stride << 1);
    } else {
        break;
    }
}
}
