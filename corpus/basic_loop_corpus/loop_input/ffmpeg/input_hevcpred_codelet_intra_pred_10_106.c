#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

union __attribute__((packed)) __attribute__((may_alias)) unaligned_64 {
    uint64_t l;
};

int i;
int size = 32 * 1024 * 1024 / 2; // Ensures 2 * size is about 64M, leading to ~64MB data access with step 4 on uint16_t
uint16_t *left;
uint64_t pix = 0x123456789ABCDEF0ULL;

void init_vars() {
    left = (uint16_t*)aligned_alloc(8, (2 * size) * sizeof(uint16_t));
    if (!left) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }
}