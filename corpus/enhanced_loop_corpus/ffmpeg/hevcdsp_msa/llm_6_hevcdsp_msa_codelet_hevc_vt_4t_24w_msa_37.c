#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern int32_t src_stride;
extern int16_t *dst;
extern int32_t dst_stride;
extern int32_t height;
extern int32_t loop_cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (loop_cnt = (height >> 2); loop_cnt--;) {
    uint8_t *src1 = src;
    uint8_t *src2 = src + src_stride;
    uint8_t *src3 = src + 2*src_stride;
    uint8_t *src4 = src + 3*src_stride;
    
    int16_t *dst1 = dst;
    int16_t *dst2 = dst + dst_stride;
    int16_t *dst3 = dst1 + 2*dst_stride;
    int16_t *dst4 = dst2 + 2*dst_stride;

    dst1[0] = (int16_t)src1[0];
    dst2[0] = (int16_t)src2[0];
    dst3[0] = (int16_t)src3[0];
    dst4[0] = (int16_t)src4[0];

    src += (4 * src_stride);
    dst += (4 * dst_stride);
}
}
