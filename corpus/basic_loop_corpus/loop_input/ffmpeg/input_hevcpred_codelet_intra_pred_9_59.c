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
    size_max_y = (1 << 20); // ~2MB of data: 1M elements * sizeof(uint16_t) = 2MB
    left = aligned_alloc(64, size_max_y * sizeof(uint16_t));
    if (!left) {
        exit(1);
    }
    for (int j = 0; j < size_max_y; ++j) {
        left[j] = 0;
    }
}