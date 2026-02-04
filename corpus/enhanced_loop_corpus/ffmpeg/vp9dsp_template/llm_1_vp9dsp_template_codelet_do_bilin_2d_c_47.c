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
    // Unroll the loop into a double nested structure with depth 2: coarse and fine iteration
    int block_size = 16;
    int num_blocks = (w + block_size - 1) / block_size;
    for (int b = 0; b < num_blocks; b++) {
        int start = b * block_size;
        int end = (start + block_size < w) ? start + block_size : w;
        for (x = start; x < end; x++) {
            if (avg) {
                dst[x] = (dst[x] + (tmp_ptr[x] + ((my * (tmp_ptr[x + 64] - tmp_ptr[x]) + 8) >> 4)) + 1) >> 1;
            } else {
                dst[x] = (tmp_ptr[x] + ((my * (tmp_ptr[x + 64] - tmp_ptr[x]) + 8) >> 4));
            }
        }
    }
}
