#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

union __attribute__((packed)) __attribute__((may_alias)) unaligned_64 {
    uint64_t l;
};

int i;
uint16_t *left;
int size_max_y;
uint64_t pix;

void init_vars() {
    pix = 0x123456789ABCDEF0ULL;
    size_max_y = (1 << 20); // 1MB of uint16_t: 524,288 elements -> ~1.3 seconds? Adjust down.
    size_max_y = (1 << 18); // 256KB: 131072 elements -> should be safe for 0.01s with loop unrolling
    size_max_y &= ~0x3; // Ensure multiple of 4 for i += 4

    left = aligned_alloc(64, sizeof(uint16_t) * size_max_y);
    if (!left) {
        exit(1);
    }
}

__attribute__((destructor))
void cleanup() {
    free(left);
}