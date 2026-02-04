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
for (loop_cnt = (height >> 2); loop_cnt--;) {
    int32_t offset_src1 = 0, offset_src2 = src_stride;
    int32_t offset_dst1 = 0, offset_dst2 = dst_stride;

    dst[offset_dst1 + 0] = (src[offset_src1 + 0] + src[offset_src2 + 0]) >> 1;
    dst[offset_dst1 + 1] = (src[offset_src1 + 1] + src[offset_src2 + 1]) >> 1;
    dst[offset_dst2 + 0] = (src[offset_src1 + 0] - src[offset_src2 + 0]) & 0xFF;
    dst[offset_dst2 + 1] = (src[offset_src1 + 1] - src[offset_src2 + 1]) & 0xFF;

    {
        uint8_t temp = src[offset_src1 + 0];
        src[offset_src1 + 0] = src[offset_src2 + 1];
        src[offset_src2 + 1] = temp;
    }

    src += (2 * src_stride);
    dst += (2 * dst_stride);

    if ((loop_cnt & 1) == 0) {
        dst += dst_stride;
        src += src_stride;
    }
}
}
