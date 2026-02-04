#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

union __attribute__((packed)) __attribute__((may_alias)) unaligned_64 {
    uint64_t l;
};

int i;
int size = 32768; // Ensures 2 * size = 65536, and total data size is ~128KB (within suggested range)
uint16_t *left;
uint64_t pix = 0x123456789ABCDEF0ULL;

void init_vars() {
    left = aligned_alloc(64, (2 * size) * sizeof(uint16_t));
    if (!left) {
        exit(1);
    }
    for (int j = 0; j < 2 * size; ++j) {
        left[j] = 0;
    }
}