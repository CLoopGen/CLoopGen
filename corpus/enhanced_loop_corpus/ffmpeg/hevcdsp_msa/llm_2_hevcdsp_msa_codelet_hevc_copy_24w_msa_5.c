#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern int32_t src_stride;
extern int16_t *dst;
extern int32_t dst_stride;
extern int32_t height;
extern uint32_t loop_cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (loop_cnt = (height >> 2); loop_cnt--;) {
        // Variant 1: Consecutive memory access with pointer pre-increment and local caching
        uint8_t *s0 = src;
        uint8_t *s1 = src + src_stride;
        uint8_t *s2 = src + 2 * src_stride;
        uint8_t *s3 = src + 3 * src_stride;
        int16_t *d0 = dst;
        int16_t *d1 = dst + dst_stride;
        int16_t *d2 = dst + 2 * dst_stride;
        int16_t *d3 = dst + 3 * dst_stride;

        for (int i = 0; i < 4; ++i) {
            d0[i] = s0[i];
            d1[i] = s1[i];
            d2[i] = s2[i];
            d3[i] = s3[i];
        }

        src += (4 * src_stride);
        dst += (4 * dst_stride);
    }
}
