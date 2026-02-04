#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern int32_t src_stride;
extern int16_t *dst;
extern int32_t dst_stride;
extern int32_t height;
extern int32_t loop_cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (loop_cnt = (height >> 2); loop_cnt--;) {
        uint8_t *s0 = src;
        uint8_t *s1 = src + src_stride;
        uint8_t *s2 = src + 2 * src_stride;
        uint8_t *s3 = src + 3 * src_stride;

        int16_t *d0 = dst;
        int16_t *d1 = dst + dst_stride;
        int16_t *d2 = dst + 2 * dst_stride;
        int16_t *d3 = dst + 3 * dst_stride;

        for (int col = 0; col < 4; ++col) {
            d0[col] = (int16_t)s0[col];
            d1[col] = (int16_t)s1[col];
            d2[col] = (int16_t)s2[col];
            d3[col] = (int16_t)s3[col];
        }

        src += 4 * src_stride;
        dst += 4 * dst_stride;
    }
}
