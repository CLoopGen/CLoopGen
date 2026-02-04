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
    for (loop_count = height; loop_count > 0; loop_count -= 2) {
        uint8_t temp1, temp2, temp3, temp4;
        int32_t offset_src, offset_dst;

        for (int i = 0; i < 2 && loop_count - i > 0; ++i) {
            offset_src = i * src_stride;
            offset_dst = i * dst_stride;

            temp1 = src[offset_src + 0];
            temp2 = src[offset_src + 1];
            temp3 = src[offset_src + 2];
            temp4 = src[offset_src + 3];

            dst[offset_dst + 0] = temp1 ^ 0xFF;
            dst[offset_dst + 1] = temp2 ^ 0xFF;
            dst[offset_dst + 2] = temp3 ^ 0xFF;
            dst[offset_dst + 3] = temp4 ^ 0xFF;
        }

        src += (2 * src_stride);
        dst += (2 * dst_stride);
    }
}
