#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

union __attribute__((packed)) __attribute__((may_alias)) unaligned_64 {
    uint64_t l;
};

int i;
int size = 32768; // Ensures ~131KB data (32768 * sizeof(uint16_t)), safe for ~0.01s runtime
uint16_t *left;

uint64_t pix = 0x123456789ABCDEF0ULL;

void init_vars() {
    left = aligned_alloc(16, (size + size + 3) * sizeof(uint16_t)); // Allocate extra space to prevent overflow when accessing left + size + i
    if (!left) exit(1);
}