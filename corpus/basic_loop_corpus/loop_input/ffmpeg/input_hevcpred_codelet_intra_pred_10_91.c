#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

union __attribute__((packed)) __attribute__((may_alias)) unaligned_64 {
    uint64_t l;
};

int i;
int size = 65536;
int top_right_size = 1024;
uint16_t *top;
uint64_t pix = 0x123456789ABCDEF0ULL;

void init_vars() {
    // Allocate top to be large enough: we access up to size + top_right_size + (size - top_right_size) - 1
    // Maximum index: size + top_right_size + (size - top_right_size) - 1 + 3 (due to i += 4, last write uses 4 elements)
    // => 2*size + top_right_size + 2, in terms of uint16_t
    // But we cast to unaligned_64 which accesses 8 bytes = 4 uint16_t per write
    // So we need at least (2*size + top_right_size + 3) uint16_t elements

    size_t total_elements = 2 * size + top_right_size + 16; // generous padding
    top = (uint16_t*)aligned_alloc(64, total_elements * sizeof(uint16_t));
    if (!top) {
        exit(1);
    }

    // Ensure the target region is accessible
    for (int j = 0; j < total_elements; j++) {
        top[j] = 0;
    }
}