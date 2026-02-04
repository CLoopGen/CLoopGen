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
extern uint8_t *dst_ptr;
extern uint8_t *src_minus1;
extern int32_t v_cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (; height; height -= 4) {
    src_minus1 = src - 1;
    for (v_cnt = 0; v_cnt < width; v_cnt += 16) {
        // Change to strided memory access: process every 4th element first, then stride through
        dst_ptr = dst + v_cnt;
        for (int stride = 0; stride < 4; ++stride) {
            uint8_t *s = src_minus1 + 16 + stride;
            uint8_t *d = dst_ptr + stride;
            for (int k = 0; k < 16; k += 4) {
                d[k +  0] = s[k +  0];
                d[k +  4] = s[k +  4];
                d[k +  8] = s[k +  8];
                d[k + 12] = s[k + 12];
            }
        }
    }
    src += (src_stride << 2);
    dst += (dst_stride << 2);
}
}
