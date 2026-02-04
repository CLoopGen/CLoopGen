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
for (loop_cnt = (height >> 1); loop_cnt--;) {
    // Strided memory access: process every 4th element across multiple rows
    const int stride_factor = 4;
    for (int i = 0; i < stride_factor; ++i) {
        if (i < src_stride && i < dst_stride) {
            dst[i] = (int16_t)(src[i]);
            dst[dst_stride + i] = (int16_t)(src[src_stride + i]);
        }
    }

    src += (2 * src_stride);
    dst += (2 * dst_stride);
}
}
