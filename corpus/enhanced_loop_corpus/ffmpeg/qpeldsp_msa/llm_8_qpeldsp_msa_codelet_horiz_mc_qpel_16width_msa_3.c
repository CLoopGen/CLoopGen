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
        int32_t offset_src = 0, offset_dst = 0;

        // Perform multiple arithmetic operations per iteration
        offset_src = 2 * src_stride;
        offset_dst = dst_stride;

        temp1 = src[offset_src + 0];
        temp2 = src[offset_src + 1];
        temp3 = src[offset_src + 2];
        temp4 = src[offset_src + 3];

        dst[offset_dst + 0] = temp1 ^ 0xFF;
        dst[offset_dst + 1] = temp2 ^ 0xFF;
        dst[offset_dst + 2] = temp3 ^ 0xFF;
        dst[offset_dst + 3] = temp4 ^ 0xFF;

        src += (2 * src_stride);
        dst += (2 * dst_stride);
    }
}
