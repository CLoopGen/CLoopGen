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
for (cnt = (height >> 3); cnt--;) {
    int offset;
    // Use indirect access via index array to simulate irregular memory access
    int indices[8] = {0, 1, 2, 3, 4, 5, 6, 7}; // Simulate configurable access pattern
    for (int i = 0; i < 8; i++) {
        offset = indices[i];
        dst[offset * dst_stride] = src[offset * src_stride];
    }
    src += (8 * src_stride);
    dst += (8 * dst_stride);
}
}
