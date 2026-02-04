#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern int32_t src_stride;
extern int16_t *dst;
extern int32_t dst_stride;
extern int32_t height;
extern uint32_t loop_cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (loop_cnt = (height >> 2); loop_cnt--;) {
        uint8_t *src0 = src;
        uint8_t *src1 = src + src_stride;
        uint8_t *src2 = src + (2 * src_stride);
        uint8_t *src3 = src + (3 * src_stride);

        int16_t *dst0 = dst;
        int16_t *dst1 = dst + dst_stride;
        int16_t *dst2 = dst + (2 * dst_stride);
        int16_t *dst3 = dst + (3 * dst_stride);

        // Simulate processing with consecutive access pattern via local pointers
        dst0[0] = src0[0];
        dst1[0] = src1[0];
        dst2[0] = src2[0];
        dst3[0] = src3[0];

        src += (4 * src_stride);
        dst += (4 * dst_stride);
    }
}
