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
    // Use indirect access via an index array to simulate irregular memory access
    static const int32_t indices[4] = {0, 1, 3, 2}; // Example permutation

    for (int j = 0; j < 4; j++) {
        offset = indices[j] * src_stride;
        dst[offset] = src[offset];
        dst[offset + 1] = src[offset + 1];
    }

    // Process next pair of rows using strided vertical jump
    src += (2 * src_stride);
    dst += (2 * dst_stride);
}
}
