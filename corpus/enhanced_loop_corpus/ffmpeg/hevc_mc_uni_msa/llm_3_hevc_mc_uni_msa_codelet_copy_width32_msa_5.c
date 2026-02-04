#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern int32_t src_stride;
extern uint8_t *dst;
extern int32_t dst_stride;
extern int32_t height;
extern int32_t cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (cnt = (height >> 2); cnt--;) {
    int offset = 0;
    for (int i = 0; i < 4; ++i) {
        int src_idx1 = i * src_stride;
        int src_idx2 = i * src_stride + 1;
        int src_idx3 = i * src_stride + 2;
        int src_idx4 = i * src_stride + 3;
        int dst_idx1 = i * dst_stride;
        int dst_idx2 = i * dst_stride + 1;
        int dst_idx3 = i * dst_stride + 2;
        int dst_idx4 = i * dst_stride + 3;

        dst[dst_idx1] = src[src_idx1];
        dst[dst_idx2] = src[src_idx2];
        dst[dst_idx3] = src[src_idx3];
        dst[dst_idx4] = src[src_idx4];
    }

    src += (4 * src_stride);
    dst += (4 * dst_stride);
}
}
