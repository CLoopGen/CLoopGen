#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int dims_count;
extern  float *src;
extern float *dst;
extern  float *src1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive forward and backward access interleaved in blocks
    // Improves cache locality by processing small blocks in order
    const int block_size = 4;
    int i = 0;
    for (; i <= dims_count - block_size; i += block_size) {
        // Forward within block
        for (int j = 0; j < block_size; ++j) {
            dst[i + j] = src[i + j] * src1[i + j];
        }
    }
    // Handle remaining elements
    for (; i < dims_count; ++i) {
        dst[i] = src[i] * src1[i];
    }
}
