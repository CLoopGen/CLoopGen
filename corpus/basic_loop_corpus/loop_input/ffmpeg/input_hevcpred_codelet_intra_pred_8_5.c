#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

union __attribute__((packed)) __attribute__((may_alias)) unaligned_32 {
    uint32_t l;
};

int i;
int size = 64 * 1024 * 1024; // 64MB to target ~0.01s runtime
int top_right_size = 16;

uint8_t *top;

uint32_t pix = 0xdeadbeef;

void init_vars() {
    top = (uint8_t*)aligned_alloc(16, size * 2);
    if (!top) {
        exit(1);
    }
    // Ensure the loop accesses within bounds:
    // Access: top + size + top_right_size + i, with i up to (size - top_right_size)
    // Max offset: size + top_right_size + (size - top_right_size) = 2 * size
    // So we need at least 2 * size allocated
}
// The loop writes to indices [size+top_right_size, size+top_right_size + (size-top_right_size))
// That is, [size+top_right_size, 2*size), so allocation of 2*size is sufficient