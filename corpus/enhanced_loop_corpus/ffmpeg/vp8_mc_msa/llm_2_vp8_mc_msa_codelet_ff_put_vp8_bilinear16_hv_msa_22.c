#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern ptrdiff_t dst_stride;
extern uint8_t *src;
extern ptrdiff_t src_stride;
extern int height;
extern uint32_t loop_cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (loop_cnt = (height >> 2); loop_cnt--;) {
        uint8_t *src0 = src;
        uint8_t *src1 = src + src_stride;
        uint8_t *src2 = src + (2 * src_stride);
        uint8_t *src3 = src + (3 * src_stride);

        {
            dst[0] = src0[0];
            dst[1] = src0[1];
            dst[2] = src0[2];
            dst[3] = src0[3];
        }
        ;
        {
            dst[dst_stride] = src1[0];
            dst[dst_stride + 1] = src1[1];
            dst[dst_stride + 2] = src1[2];
            dst[dst_stride + 3] = src1[3];
        }
        ;
        src += (4 * src_stride);
        {
            dst[2 * dst_stride] = src2[0];
            dst[2 * dst_stride + 1] = src2[1];
            dst[2 * dst_stride + 2] = src2[2];
            dst[2 * dst_stride + 3] = src2[3];
        }
        ;
        {
            dst[3 * dst_stride] = src3[0];
            dst[3 * dst_stride + 1] = src3[1];
            dst[3 * dst_stride + 2] = src3[2];
            dst[3 * dst_stride + 3] = src3[3];
        }
        ;
        dst += 4 * dst_stride;
    }
}
