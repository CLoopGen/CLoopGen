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
// Change to strided memory access: process one row at a time but step through columns with larger stride
int block_height = 4;
int step = 8; // Stride in elements (simulate cache-friendly or SIMD-like access)

for (cnt = (height >> 2); cnt--;) {
    for (int col = 0; col < step; col += 8) {
        // Process 8 bytes at a time across 4 rows — strided access
        if (col + 7 < 64) { // Assume fixed width of 64 for realism
            dst[col + 0] = src[col + 0];
            dst[col + 1] = src[col + 1];
            dst[col + 2] = src[col + 2];
            dst[col + 3] = src[col + 3];
            dst[col + 4] = src[col + 4];
            dst[col + 5] = src[col + 5];
            dst[col + 6] = src[col + 6];
            dst[col + 7] = src[col + 7];

            dst[dst_stride + col + 0] = src[src_stride + col + 0];
            dst[dst_stride + col + 1] = src[src_stride + col + 1];
            dst[dst_stride + col + 2] = src[src_stride + col + 2];
            dst[dst_stride + col + 3] = src[src_stride + col + 3];
            dst[dst_stride + col + 4] = src[src_stride + col + 4];
            dst[dst_stride + col + 5] = src[src_stride + col + 5];
            dst[dst_stride + col + 6] = src[src_stride + col + 6];
            dst[dst_stride + col + 7] = src[src_stride + col + 7];

            dst[2*dst_stride + col + 0] = src[2*src_stride + col + 0];
            dst[2*dst_stride + col + 1] = src[2*src_stride + col + 1];
            dst[2*dst_stride + col + 2] = src[2*src_stride + col + 2];
            dst[2*dst_stride + col + 3] = src[2*src_stride + col + 3];
            dst[2*dst_stride + col + 4] = src[2*src_stride + col + 4];
            dst[2*dst_stride + col + 5] = src[2*src_stride + col + 5];
            dst[2*dst_stride + col + 6] = src[2*src_stride + col + 6];
            dst[2*dst_stride + col + 7] = src[2*src_stride + col + 7];

            dst[3*dst_stride + col + 0] = src[3*src_stride + col + 0];
            dst[3*dst_stride + col + 1] = src[3*src_stride + col + 1];
            dst[3*dst_stride + col + 2] = src[3*src_stride + col + 2];
            dst[3*dst_stride + col + 3] = src[3*src_stride + col + 3];
            dst[3*dst_stride + col + 4] = src[3*src_stride + col + 4];
            dst[3*dst_stride + col + 5] = src[3*src_stride + col + 5];
            dst[3*dst_stride + col + 6] = src[3*src_stride + col + 6];
            dst[3*dst_stride + col + 7] = src[3*src_stride + col + 7];
        }
    }
    src += (4 * src_stride);
    dst += (4 * dst_stride);
}
}
