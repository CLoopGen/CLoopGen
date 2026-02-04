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
    int offset;
    // Use indirect access via index array to simulate irregular but deterministic pattern
    int indices[4] = {0, src_stride, 2*src_stride, 3*src_stride};

    for (int col = 0; col < 4; ++col) {
        offset = indices[col];
        dst[offset + 0 * dst_stride] = src[offset + 0 * src_stride];
        dst[offset + 1 * dst_stride] = src[offset + 1 * src_stride];
        dst[offset + 2 * dst_stride] = src[offset + 2 * src_stride];
        dst[offset + 3 * dst_stride] = src[offset + 3 * src_stride];
    }

    src += (4 * src_stride);
    dst += (4 * dst_stride);
}
}
