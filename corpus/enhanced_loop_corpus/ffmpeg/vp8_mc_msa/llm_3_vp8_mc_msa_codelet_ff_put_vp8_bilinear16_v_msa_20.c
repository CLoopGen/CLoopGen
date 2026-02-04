#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern ptrdiff_t dst_stride;
extern uint8_t *src;
extern ptrdiff_t src_stride;
extern int height;
extern uint32_t loop_cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (loop_cnt = (height >> 2); loop_cnt--;) {
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            size_t src_idx = i * 4 + j;
            size_t dst_idx = j * 4 + i;
            dst[dst_idx] = src[src_idx];
        }
    }

    src += (4 * src_stride);
    dst += (4 * dst_stride);
}
}
