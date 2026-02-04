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
    // Consecutive prefetch-style access with local blocking
    const int block_size = 8;
    for (loop_cnt = height; loop_cnt--;) {
        uint8_t local_src[block_size];
        int16_t local_dst[block_size];

        // Load a block of source using consecutive access (cache-friendly)
        for (int i = 0; i < block_size; ++i) {
            local_src[i] = src[i];
        }

        // Process block with simple transformation
        for (int i = 0; i < block_size; ++i) {
            local_dst[i] = (int16_t)(local_src[i]) - 128;
        }

        // Store results consecutively
        for (int i = 0; i < block_size; ++i) {
            ((int16_t*)dst)[i] = local_dst[i];
        }

        src += src_stride;
        dst += dst_stride;
    }
}
