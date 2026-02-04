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
    for (loop_count = (height >> 1); loop_count--;) {
        uint8_t temp1, temp2, temp3, temp4;
        int32_t offset_src, offset_dst;

        offset_src = 0;
        offset_dst = 0;

        for (int i = 0; i < 2; ++i) {
            offset_src = i * src_stride;
            offset_dst = i * dst_stride;

            temp1 = src[offset_src + 0];
            temp2 = src[offset_src + 1];
            temp3 = dst[offset_dst + 0];
            temp4 = dst[offset_dst + 1];

            dst[offset_dst + 0] = temp1 ^ temp3;
            dst[offset_dst + 1] = temp2 ^ temp4;
        }

        src += (2 * src_stride);
        dst += (2 * dst_stride);
    }
}
