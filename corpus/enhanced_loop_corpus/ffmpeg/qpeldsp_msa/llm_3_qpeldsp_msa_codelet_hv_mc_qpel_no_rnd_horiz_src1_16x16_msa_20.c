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
for (loop_count = (height >> 2); loop_count--;) {
    for (int i = 0; i < 4; ++i) {
        int src_idx = i * src_stride;
        int dst_idx = i * dst_stride;
        dst[dst_idx] = src[src_idx];
    }
    src += (4 * src_stride);
    dst += (4 * dst_stride);
}
}
