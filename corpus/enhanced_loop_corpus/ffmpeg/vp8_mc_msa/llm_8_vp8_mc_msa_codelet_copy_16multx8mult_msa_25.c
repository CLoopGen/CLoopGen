#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern int32_t src_stride;
extern uint8_t *dst;
extern int32_t dst_stride;
extern int32_t height;
extern int32_t width;
extern int32_t cnt;
extern int32_t loop_cnt;
extern uint8_t *src_tmp;
extern uint8_t *dst_tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (cnt = (width >> 3); cnt--;) {
    src_tmp = src;
    dst_tmp = dst;
    for (loop_cnt = (height >> 2); loop_cnt--;) {
        {
            {
                uint8_t a0 = src_tmp[0 * src_stride + 0];
                uint8_t a1 = src_tmp[0 * src_stride + 1];
                uint8_t a2 = src_tmp[1 * src_stride + 0];
                uint8_t a3 = src_tmp[1 * src_stride + 1];
                uint8_t sum = a0 + a1 + a2 + a3;
                dst_tmp[0 * dst_stride + 0] = sum;
            }
            ;
            {
                uint8_t b0 = src_tmp[2 * src_stride + 2];
                uint8_t b1 = src_tmp[2 * src_stride + 3];
                uint8_t b2 = src_tmp[3 * src_stride + 2];
                uint8_t b3 = src_tmp[3 * src_stride + 3];
                uint8_t avg = (b0 + b1 + b2 + b3) >> 2;
                dst_tmp[1 * dst_stride + 1] = avg;
            }
            ;
        }
        ;
        {
            {
                uint8_t c0 = src_tmp[4 * src_stride + 4];
                uint8_t c1 = src_tmp[4 * src_stride + 5];
                uint8_t c2 = src_tmp[5 * src_stride + 4];
                uint8_t c3 = src_tmp[5 * src_stride + 5];
                uint8_t max_val = c0;
                if (c1 > max_val) max_val = c1;
                if (c2 > max_val) max_val = c2;
                if (c3 > max_val) max_val = c3;
                dst_tmp[2 * dst_stride + 2] = max_val;
            }
            ;
            {
                uint8_t d0 = src_tmp[6 * src_stride + 6];
                uint8_t d1 = src_tmp[6 * src_stride + 7];
                uint8_t d2 = src_tmp[7 * src_stride + 6];
                uint8_t d3 = src_tmp[7 * src_stride + 7];
                uint8_t xor_val = d0 ^ d1 ^ d2 ^ d3;
                dst_tmp[3 * dst_stride + 3] = xor_val;
            }
            ;
        }
        ;
        src_tmp += (4 * src_stride);
        {
            {
                uint8_t e0 = src_tmp[0 * src_stride + 0];
                uint8_t e1 = src_tmp[0 * src_stride + 1];
                uint8_t res1 = (e0 + e1) >> 1;
                dst_tmp[0 * dst_stride + 1] = res1;
            }
            ;
            {
                uint8_t f0 = src_tmp[1 * src_stride + 0];
                uint8_t f1 = src_tmp[1 * src_stride + 1];
                uint8_t res2 = (f0 + f1) >> 1;
                dst_tmp[1 * dst_stride + 0] = res2;
            }
            ;
        }
        ;
        dst_tmp += (4 * dst_stride);
    }
    src += 8;
    dst += 8;
}
}
