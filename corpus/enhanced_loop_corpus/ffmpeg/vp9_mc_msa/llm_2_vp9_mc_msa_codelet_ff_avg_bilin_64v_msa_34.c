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
    uint8_t *dst0 = dst;
    uint8_t *dst1 = dst + dst_stride;

    for (loop_cnt = (height >> 1); loop_cnt--;) {
        {
            dst0[0] = src0[0];
            dst0[1] = src0[1];
            dst0[2] = src0[2];
            dst0[3] = src0[3];
        }
        ;
        {
            dst1[0] = src1[0];
            dst1[1] = src1[1];
            dst1[2] = src1[2];
            dst1[3] = src1[3];
        }
        ;
        {
            dst0[4] = src0[4];
            dst0[5] = src0[5];
            dst0[6] = src0[6];
            dst0[7] = src0[7];
        }
        ;
        {
            dst1[4] = src1[4];
            dst1[5] = src1[5];
            dst1[6] = src1[6];
            dst1[7] = src1[7];
        }
        ;
        src0 += (2 * src_stride);
        src1 += (2 * src_stride);
        dst0 += (2 * dst_stride);
        dst1 += (2 * dst_stride);
    }

    src = src0;
    dst = dst0;
}
