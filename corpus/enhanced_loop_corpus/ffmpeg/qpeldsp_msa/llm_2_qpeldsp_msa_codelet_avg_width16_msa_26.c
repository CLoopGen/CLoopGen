#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern int32_t src_stride;
extern uint8_t *dst;
extern int32_t dst_stride;
extern int32_t height;
extern int32_t cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (cnt = (height / 8); cnt--;) {
    uint8_t *src0 = src;
    uint8_t *src1 = src + src_stride;
    uint8_t *src2 = src + 2 * src_stride;
    uint8_t *src3 = src + 3 * src_stride;
    uint8_t *src4 = src + 4 * src_stride;
    uint8_t *src5 = src + 5 * src_stride;
    uint8_t *src6 = src + 6 * src_stride;
    uint8_t *src7 = src + 7 * src_stride;

    uint8_t *dst0 = dst;
    uint8_t *dst1 = dst + dst_stride;
    uint8_t *dst2 = dst + 2 * dst_stride;
    uint8_t *dst3 = dst + 3 * dst_stride;
    uint8_t *dst4 = dst + 4 * dst_stride;
    uint8_t *dst5 = dst + 5 * dst_stride;
    uint8_t *dst6 = dst + 6 * dst_stride;
    uint8_t *dst7 = dst + 7 * dst_stride;

    for (int i = 0; i < 8; ++i) {
        dst0[i] = src0[i];
        dst1[i] = src1[i];
        dst2[i] = src2[i];
        dst3[i] = src3[i];
        dst4[i] = src4[i];
        dst5[i] = src5[i];
        dst6[i] = src6[i];
        dst7[i] = src7[i];
    }

    src += 8 * src_stride;
    dst += 8 * dst_stride;
}
}
