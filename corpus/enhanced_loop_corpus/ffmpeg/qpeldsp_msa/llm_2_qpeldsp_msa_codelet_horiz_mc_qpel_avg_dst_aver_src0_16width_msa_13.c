#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern int32_t src_stride;
extern uint8_t *dst;
extern int32_t dst_stride;
extern int32_t height;
extern uint8_t loop_count;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (loop_count = (height >> 2); loop_count--;) {
    uint8_t *src1 = src;
    uint8_t *src2 = src + src_stride;
    uint8_t *src3 = src + 2 * src_stride;
    uint8_t *src4 = src + 3 * src_stride;
    
    uint8_t *dst1 = dst;
    uint8_t *dst2 = dst + dst_stride;
    
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            dst1[j] = src1[j];
            dst1[j + 2] = src2[j];
            dst2[j] = src3[j];
            dst2[j + 2] = src4[j];
        }
        dst1 += dst_stride;
        dst2 += dst_stride;
        src1 += 2;
        src2 += 2;
        src3 += 2;
        src4 += 2;
    }

    src += 4 * src_stride;
    dst += 4 * dst_stride;
}
}
