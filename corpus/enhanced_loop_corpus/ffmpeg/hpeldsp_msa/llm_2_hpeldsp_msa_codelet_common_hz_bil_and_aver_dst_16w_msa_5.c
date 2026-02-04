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
for (loop_cnt = (height >> 3); loop_cnt--;) {
    uint8_t *src0 = src;
    uint8_t *src1 = src + src_stride;
    uint8_t *src2 = src + 2*src_stride;
    uint8_t *src3 = src + 3*src_stride;
    uint8_t *src4 = src + 4*src_stride;
    uint8_t *src5 = src + 5*src_stride;
    uint8_t *src6 = src + 6*src_stride;
    uint8_t *src7 = src + 7*src_stride;

    uint8_t *dst0 = dst;
    uint8_t *dst1 = dst + dst_stride;

    for (int i = 0; i < 4; ++i) {
        dst0[i] = src0[i];
        dst0[i + 4] = src1[i];
        dst0[i + 8] = src2[i];
        dst0[i + 12] = src3[i];

        dst1[i] = src4[i];
        dst1[i + 4] = src5[i];
        dst1[i + 8] = src6[i];
        dst1[i + 12] = src7[i];
    }

    src += (8 * src_stride);
    dst += (8 * dst_stride);
}
}
