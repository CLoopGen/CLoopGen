#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern int32_t src_stride;
extern uint8_t *dst;
extern int32_t dst_stride;
extern int32_t height;
extern int32_t cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (cnt = (height >> 2); cnt--;) {
    uint8_t *src1 = src;
    uint8_t *src2 = src + src_stride;
    uint8_t *src3 = src + (2 * src_stride);
    uint8_t *src4 = src + (3 * src_stride);
    
    uint8_t *dst1 = dst;
    uint8_t *dst2 = dst + dst_stride;
    uint8_t *dst3 = dst + (2 * dst_stride);
    uint8_t *dst4 = dst + (3 * dst_stride);

    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            dst1[j] = src1[j];
            dst2[j] = src2[j];
            dst3[j] = src3[j];
            dst4[j] = src4[j];
        }
        src1 += src_stride;
        src2 += src_stride;
        src3 += src_stride;
        src4 += src_stride;
        dst1 += dst_stride;
        dst2 += dst_stride;
        dst3 += dst_stride;
        dst4 += dst_stride;
    }

    src += (4 * src_stride);
    dst += (4 * dst_stride);
}
}
