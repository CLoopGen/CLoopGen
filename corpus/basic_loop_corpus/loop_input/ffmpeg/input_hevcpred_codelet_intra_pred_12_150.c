#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

union __attribute__((packed)) __attribute__((may_alias)) unaligned_64 {
    uint64_t l;
};

int i;
int size = 32 * 1024 * 1024 / 2; // Each iteration writes 8 bytes, total ~256MB / 2 because of 2*size in loop bound
uint16_t *left;
uint64_t pix = 0x1111222233334444ULL;

void init_vars() {
    left = (uint16_t*)aligned_alloc(8, (2 * size) * sizeof(uint16_t));
    if (!left) {
        exit(1);
    }
    for (int j = 0; j < 2 * size; ++j) {
        left[j] = 0;
    }
}