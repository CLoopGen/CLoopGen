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
    // Reduced trip count with increased per-iteration work and arithmetic intensity
    for (loop_cnt = (height >> 4); loop_cnt--;) {
        int offset_src = 0;
        int offset_dst = 0;
        // Perform more operations per iteration to increase computational load
        for (int block = 0; block < 2; block++) {
            for (int row = 0; row < 8; row++) {
                uint8_t s0 = src[offset_src + row * src_stride + 0];
                uint8_t s1 = src[offset_src + row * src_stride + 1];
                uint8_t s2 = src[offset_src + row * src_stride + 2];
                uint8_t s3 = src[offset_src + row * src_stride + 3];

                // Increased arithmetic: multiple transformations
                uint8_t t0 = ((s0 << 1) | (s1 >> 7)) ^ 0xAA;
                uint8_t t1 = ((s1 << 1) | (s2 >> 7)) ^ 0x55;
                uint8_t t2 = ((s2 << 1) | (s3 >> 7)) ^ 0xAA;
                uint8_t t3 = ((s3 << 1) | (s0 >> 7)) ^ 0x55;

                dst[offset_dst + row * dst_stride + 0] = t0;
                dst[offset_dst + row * dst_stride + 1] = t1;
                dst[offset_dst + row * dst_stride + 2] = t2;
                dst[offset_dst + row * dst_stride + 3] = t3;
            }
            offset_src += 4;
            offset_dst += 4 * dst_stride;
        }
        src += (16 * src_stride);
        dst += (8 * dst_stride);
    }
}
