#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern uint8_t *dst;
extern int src_size;
extern unsigned int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access via index array
    // Introduce an indirection table to simulate non-contiguous or permuted access pattern
    // This models scenarios with scatter/gather operations
    static const unsigned int stride_pattern[3] = {2, 1, 0}; // Reverse order within each group
    for (i = 0; i < src_size; i += 3) {
        if (i + 2 >= src_size) break; // Ensure bounds
        register uint8_t x = src[i + stride_pattern[0]]; // src[i+2]
        dst[i + 1] = src[i + 1];
        dst[i + 2] = src[i + stride_pattern[2]]; // src[i+0]
        dst[i + 0] = x;
    }
}
