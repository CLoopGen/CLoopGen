#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern int32_t src_stride;
extern uint8_t *dst;
extern int32_t dst_stride;
extern int32_t height;
extern uint32_t loop_cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (loop_cnt = (height >> 1); loop_cnt--;) {
    uint8_t *src1 = src;
    uint8_t *src2 = src + src_stride;
    uint8_t *dst1 = dst;
    uint8_t *dst2 = dst + dst_stride;

    for (int i = 0; i < 16; i++) {
        dst1[i] = src1[i];
        dst2[i] = src2[i];
    }

    src += (2 * src_stride);
    dst += (2 * dst_stride);
}
}
