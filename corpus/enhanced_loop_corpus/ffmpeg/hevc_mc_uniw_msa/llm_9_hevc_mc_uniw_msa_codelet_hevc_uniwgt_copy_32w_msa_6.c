#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern int32_t src_stride;
extern uint8_t *dst;
extern int32_t dst_stride;
extern int32_t height;
extern uint32_t loop_cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (loop_cnt = (height >> 2); loop_cnt--;) {
    {
        __builtin_prefetch(src + 3 * src_stride, 0, 1);
        __builtin_prefetch(dst + 3 * dst_stride, 1, 1);
    }
    ;
    {
        uint8_t s0, s1, d0;
        s0 = src[0];
        s1 = src[src_stride];
        d0 = (s0 >> 1) | (s1 << 7);
        dst[0] = d0 ^ 0x55;
        dst[dst_stride] = (d0 << 1) | (s0 & 0x01);
    }
    ;
    {
        uint8_t s2, s3, d1;
        s2 = src[1];
        s3 = src[src_stride + 1];
        d1 = (s2 >> 2) | (s3 << 6);
        dst[1] = d1 ^ 0xAA;
        dst[dst_stride + 1] = (d1 << 2) | ((s2 >> 6) & 0x03);
    }
    ;
    src += (4 * src_stride);
    {
        int offset = dst_stride >> 1;
        dst[2] ^= dst[offset + 2] ^ dst[dst_stride + 2];
        dst[3] ^= dst[offset + 3] ^ dst[dst_stride + 3];
    }
    ;
    {
        uint32_t acc = 0;
        for (int j = 0; j < 8; ++j) {
            acc += src[j % 4] * dst[j % 4];
        }
        dst[4] = (uint8_t)(acc & 0xFF);
    }
    ;
    dst += (4 * dst_stride);
}
}
