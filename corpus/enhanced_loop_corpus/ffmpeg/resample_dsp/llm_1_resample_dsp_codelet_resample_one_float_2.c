#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int dst_size;
extern int64_t index2;
extern int64_t incr;
extern float *dst;
extern  float *src;
extern int dst_index;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int block_size = 4;
    int num_blocks = (dst_size + block_size - 1) / block_size;
    for (int b = 0; b < num_blocks; b++) {
        for (int offset = 0; offset < block_size; offset++) {
            int dst_index = b * block_size + offset;
            if (dst_index < dst_size) {
                dst[dst_index] = src[index2 >> 32];
                index2 += incr;
            }
        }
    }
}
