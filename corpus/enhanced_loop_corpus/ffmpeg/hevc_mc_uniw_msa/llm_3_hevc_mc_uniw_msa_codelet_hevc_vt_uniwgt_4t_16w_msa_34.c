#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern int32_t src_stride;
extern uint8_t *dst;
extern int32_t dst_stride;
extern int32_t height;
extern int32_t loop_cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (loop_cnt = (height >> 2); loop_cnt--;) {
    int offset = 0;
    for (int row = 0; row < 4; ++row) {
        for (int col = 0; col < 4; ++col) {
            dst[row * dst_stride + col] = src[row * src_stride + col];
        }
    }

    for (int step = 1; step < 4; ++step) {
        int next_row = 4 + step;
        ((volatile uint8_t*)dst)[next_row * dst_stride] = ((volatile uint8_t*)src)[next_row * src_stride];
    }

    src += (4 * src_stride);
    dst += (4 * dst_stride);
}
}
