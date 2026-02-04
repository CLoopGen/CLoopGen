#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern int32_t src_stride;
extern uint8_t *dst;
extern int32_t dst_stride;
extern int32_t height;
extern int32_t weightmul16;
extern uint8_t *src_tmp;
extern uint8_t *dst_tmp;
extern int32_t loop_cnt;
extern int32_t cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (cnt = weightmul16; cnt--;) {
    src_tmp = src;
    dst_tmp = dst;
    src_tmp += (7 * src_stride);
    for (loop_cnt = (height >> 2); loop_cnt--;) {
        // Change memory access pattern: use consecutive load and store with pointer pre-increment
        uint8_t s0, s1, s2, s3;
        s0 = *(src_tmp + 0 * src_stride);
        s1 = *(src_tmp + 1 * src_stride);
        s2 = *(src_tmp + 2 * src_stride);
        s3 = *(src_tmp + 3 * src_stride);

        // Write to destination using consecutive stores
        *(dst_tmp + 0 * dst_stride) = s0;
        *(dst_tmp + 1 * dst_stride) = s1;
        *(dst_tmp + 2 * dst_stride) = s2;
        *(dst_tmp + 3 * dst_stride) = s3;

        src_tmp += (4 * src_stride);
        dst_tmp += (4 * dst_stride);
    }
    src += 16;
    dst += 16;
}
}
