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
for (loop_cnt = (height >> 2); loop_cnt--;) {
    uint8_t *src0 = src;
    uint8_t *src1 = src + src_stride;
    uint8_t *src2 = src + (2 * src_stride);
    uint8_t *src3 = src + (3 * src_stride);

    {
        __builtin_prefetch(src0, 0, 1);
        __builtin_prefetch(src1, 0, 1);
        __builtin_prefetch(src2, 0, 1);
        __builtin_prefetch(src3, 0, 1);
    }
    ;
    {
        dst[0] = src0[0];
        dst[1] = src0[1];
        dst[2] = src0[2];
        dst[3] = src0[3];
    }
    ;
    dst += dst_stride;
    {
        dst[0] = src1[0];
        dst[1] = src1[1];
        dst[2] = src1[2];
        dst[3] = src1[3];
    }
    ;
    dst += dst_stride;
    {
        dst[0] = src2[0];
        dst[1] = src2[1];
        dst[2] = src2[2];
        dst[3] = src2[3];
    }
    ;
    dst += dst_stride;
    {
        dst[0] = src3[0];
        dst[1] = src3[1];
        dst[2] = src3[2];
        dst[3] = src3[3];
    }
    ;
    dst += dst_stride;
    src += (4 * src_stride);
}
}
