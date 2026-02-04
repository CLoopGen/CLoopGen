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
// Interleaved strided access: process two rows at a time with alternating strides
for (loop_count = (height >> 2); loop_count--;) {
    // Access pattern: treat blocks as transposed or interleaved
    for (int offset = 0; offset < 4; ++offset) {
        int src_idx = offset * src_stride;
        int dst_idx = offset * dst_stride;

        // Consecutive write to destination, strided read from source
        for (int col = 0; col < 64; ++col) { // Assume fixed row width of 64 for realism
            dst[dst_idx + col] = src[src_idx + col];
        }
    }

    // Advance pointers by full block height
    src += (4 * src_stride);
    dst += (4 * dst_stride);
}
}
