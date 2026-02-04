#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern int32_t src_stride;
extern uint8_t *dst;
extern int32_t dst_stride;
extern int32_t height;
extern int32_t cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (cnt = (height >> 2); cnt--;) {
    // Change to strided memory access: process one byte per row, stepping through columns in a strided pattern
    for (int col = 0; col < 4; ++col) {
        dst[0 * dst_stride + col] = src[0 * src_stride + col];
        dst[1 * dst_stride + col] = src[1 * src_stride + col];
        dst[2 * dst_stride + col] = src[2 * src_stride + col];
        dst[3 * dst_stride + col] = src[3 * src_stride + col];
    }

    src += (4 * src_stride);
    dst += (4 * dst_stride);
}
}
