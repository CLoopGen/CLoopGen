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
for (; height > 0; height -= 2) {
    src_minus1 = src - 1;
    for (v_cnt = 0; v_cnt < width; v_cnt += 32) {
        src_minus1 += 32;
        dst_ptr = dst + v_cnt;

        for (int unroll = 0; unroll < 32; unroll += 4) {
            uint8_t a = src_minus1[unroll];
            uint8_t b = src_minus1[unroll + 1];
            uint8_t c = src_minus1[unroll + 2];
            uint8_t d = src_minus1[unroll + 3];

            uint8_t val1 = (a + b) >> 1;
            uint8_t val2 = (b + c) >> 1;
            uint8_t val3 = (c + d) >> 1;
            uint8_t val4 = (d + a) >> 1;

            dst_ptr[unroll] = val1 ^ 0xFF;
            dst_ptr[unroll + 1] = val2 ^ 0xFF;
            dst_ptr[unroll + 2] = val3 ^ 0xFF;
            dst_ptr[unroll + 3] = val4 ^ 0xFF;

            if (height > 1) {
                dst_ptr[unroll + dst_stride] = (val1 + val2) / 2;
                dst_ptr[unroll + 1 + dst_stride] = (val2 + val3) / 2;
                dst_ptr[unroll + 2 + dst_stride] = (val3 + val4) / 2;
                dst_ptr[unroll + 3 + dst_stride] = (val4 + val1) / 2;
            }
        }
    }

    src += (src_stride << 1);
    dst += (dst_stride << 1);
}
}
