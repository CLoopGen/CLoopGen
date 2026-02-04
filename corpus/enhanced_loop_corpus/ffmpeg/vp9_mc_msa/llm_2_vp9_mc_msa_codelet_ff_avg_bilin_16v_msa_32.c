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
    uint8_t *src0 = src;
    uint8_t *src1 = src + src_stride;
    uint8_t *src2 = src + (2 * src_stride);
    uint8_t *src3 = src + (3 * src_stride);
    for (loop_cnt = (height >> 2); loop_cnt--;) {
        dst[0] = src0[0];
        dst[1] = src1[1];
        dst[2] = src2[2];
        dst[3] = src3[3];

        src0 += (4 * src_stride);
        src1 += (4 * src_stride);
        src2 += (4 * src_stride);
        src3 += (4 * src_stride);

        dst += dst_stride;
        dst += dst_stride;
        dst += dst_stride;
        dst += dst_stride;
    }
}
