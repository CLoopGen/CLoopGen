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
extern uint8_t *dst_dup;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (cnt = (height / 4); cnt--;) {
    uint8_t *src0 = src;
    uint8_t *src1 = src + src_stride;
    uint8_t *src2 = src + 2 * src_stride;
    uint8_t *src3 = src + 3 * src_stride;
    
    uint8_t *dst0 = dst;
    uint8_t *dst1 = dst + dst_stride;
    uint8_t *dst2 = dst + 2 * dst_stride;
    uint8_t *dst3 = dst + 3 * dst_stride;
    
    uint8_t *dstdup0 = dst_dup;
    uint8_t *dstdup1 = dst_dup + dst_stride;
    uint8_t *dstdup2 = dst_dup + 2 * dst_stride;
    uint8_t *dstdup3 = dst_dup + 3 * dst_stride;

    for (int i = 0; i < 4; ++i) {
        dst0[i] = src0[i];
        dst1[i] = src1[i];
        dst2[i] = src2[i];
        dst3[i] = src3[i];
        
        dstdup0[i] = src0[i];
        dstdup1[i] = src1[i];
        dstdup2[i] = src2[i];
        dstdup3[i] = src3[i];
    }

    src += 4 * src_stride;
    dst += 4 * dst_stride;
    dst_dup += 4 * dst_stride;
}
}
