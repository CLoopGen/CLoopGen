#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int w;
extern int my;
extern int avg;
extern uint8_t *tmp_ptr;
extern uint8_t *dst;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive access using local blocking (tiling) with block size 4
    // Improves spatial locality by processing small chunks
    const int block_size = 4;
    for (x = 0; x < w; x += block_size) {
        uint8_t local_tmp[block_size + 64]; // Local cache for tmp_ptr segment
        // Prefetch a block of tmp_ptr data (including offset region)
        for (int b = 0; b < block_size + 64; b++) {
            local_tmp[b] = tmp_ptr[x + b];
        }
        for (int b = 0; b < block_size && (x + b) < w; b++) {
            int idx = x + b;
            if (avg) {
                dst[idx] = (dst[idx] + (local_tmp[b] + ((my * (local_tmp[b + 64] - local_tmp[b]) + 8) >> 4)) + 1) >> 1;
            } else {
                dst[idx] = (local_tmp[b] + ((my * (local_tmp[b + 64] - local_tmp[b]) + 8) >> 4));
            }
        }
    }
}
