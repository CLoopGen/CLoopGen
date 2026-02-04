#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern ptrdiff_t dst_stride;
extern uint8_t *src;
extern ptrdiff_t src_stride;
extern uint32_t loop_cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (; loop_cnt--;) {
    // Change to indirect memory access using index array
    static const int indices[4] = {0, 2, 1, 3}; // Example permutation
    uint8_t temp_src[4], temp_dst[4];

    // Strided read through indirect indexing
    for (int i = 0; i < 4; ++i) {
        int idx = indices[i];
        temp_src[i] = *(src + idx * src_stride);
        temp_dst[i] = *(dst + idx * dst_stride);
    }

    // Perform dummy operations
    for (int i = 0; i < 4; ++i) {
        temp_dst[i] ^= temp_src[i]; // Example operation
    }

    // Write back with same indirect pattern
    for (int i = 0; i < 4; ++i) {
        int idx = indices[i];
        *(dst + idx * dst_stride) = temp_dst[i];
    }

    src += (4 * src_stride);
    dst += (4 * dst_stride);
}
}
