#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern ptrdiff_t dst_stride;
extern  uint8_t *src;
extern ptrdiff_t src_stride;
extern uint32_t loop_cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t *src0 = src;
    uint8_t *src1 = src + src_stride;
    uint8_t *src2 = src + 2 * src_stride;
    uint8_t *src3 = src + 3 * src_stride;

    uint8_t *dst0 = dst;
    uint8_t *dst1 = dst + dst_stride;
    uint8_t *dst2 = dst + 2 * dst_stride;
    uint8_t *dst3 = dst + 3 * dst_stride;

    for (; loop_cnt--;) {
        dst0[0] = src0[0];
        dst1[0] = src1[0];
        dst2[0] = src2[0];
        dst3[0] = src3[0];

        src0 += 4 * src_stride;
        src1 += 4 * src_stride;
        src2 += 4 * src_stride;
        src3 += 4 * src_stride;

        dst0 += 4 * dst_stride;
        dst1 += 4 * dst_stride;
        dst2 += 4 * dst_stride;
        dst3 += 4 * dst_stride;
    }

    src = src0;
    dst = dst0;
}
