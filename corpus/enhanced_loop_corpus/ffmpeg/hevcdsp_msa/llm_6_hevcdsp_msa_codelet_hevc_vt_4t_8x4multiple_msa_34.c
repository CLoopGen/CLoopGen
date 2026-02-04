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
    int32_t offset_src = 0;
    int32_t offset_dst = 0;
    // Introduce loop-carried dependency via offset accumulation
    for (int i = 0; i < 4; ++i) {
        dst[offset_dst] = (int16_t)(src[offset_src]);
        offset_src += src_stride;
        offset_dst += dst_stride;
    }
    // Update pointers after processing block
    src += (4 * src_stride);
    dst += (4 * dst_stride);
}
}
