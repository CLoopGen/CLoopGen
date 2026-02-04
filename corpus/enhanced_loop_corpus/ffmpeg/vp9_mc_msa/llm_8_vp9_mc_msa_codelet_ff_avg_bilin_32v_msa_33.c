#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern ptrdiff_t dst_stride;
extern  uint8_t *src;
extern ptrdiff_t src_stride;
extern int height;
extern uint32_t loop_cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (loop_cnt = (height >> 1); loop_cnt--;) {
        uint8_t s0, s1, s2, s3;
        uint8_t *src0 = src;
        uint8_t *src1 = src + src_stride;
        uint8_t *src2 = src + (2 * src_stride);
        uint8_t *src3 = src + (3 * src_stride);
        
        for (int i = 0; i < 8; i += 4) {
            s0 = src0[i];
            s1 = src1[i];
            s2 = src2[i];
            s3 = src3[i];

            dst[i] = (s0 + s1 + s2 + s3) >> 2;
        }

        for (int i = 8; i < 16; i += 4) {
            s0 = src0[i];
            s1 = src1[i];
            s2 = src2[i];
            s3 = src3[i];

            dst[i] = (s0 * 3 + s1 * 2 + s2 * 2 + s3) / 8;
        }

        src += (2 * src_stride);
        dst += (2 * dst_stride);
    }
}
