#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern int32_t src_stride;
extern int16_t *dst;
extern int32_t dst_stride;
extern int32_t height;
extern uint32_t loop_cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (loop_cnt = (height >> 1); loop_cnt--;) {
        // Variant 2: Strided memory access with transposed indexing
        // Access every 4th element in a strided manner to simulate cache-friendly tiling
        const int stride_factor = 4;
        int width = dst_stride / sizeof(int16_t);  // Assuming dst_stride is in bytes

        for (int s = 0; s < stride_factor; ++s) {
            for (int col = s; col < width; col += stride_factor) {
                int src_idx1 = (col * sizeof(uint8_t)) + 0;
                int src_idx2 = src_idx1 + src_stride * sizeof(uint8_t);
                dst[col] = (int16_t)src[src_idx1] + 128;
                dst[col + width] = (int16_t)src[src_idx2] + 128;
            }
        }

        src += (src_stride << 1);
        dst += (dst_stride << 1);
    }
}
