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
    int offset;
    // Use indirect access via index array to simulate irregular memory access
    static const uint32_t indices[8] = {0, 2, 4, 6, 8, 10, 12, 14};

    for (int j = 0; j < 8; j++) {
        offset = indices[j];
        dst[offset + 0] = src[offset + 0];
        dst[offset + 1] = src[offset + 1];
    }

    for (int j = 0; j < 8; j++) {
        offset = indices[j];
        dst[dst_stride + offset + 0] = src[src_stride + offset + 0];
        dst[dst_stride + offset + 1] = src[src_stride + offset + 1];
    }

    src += (2 * src_stride);
    dst += (2 * dst_stride);
}
}
