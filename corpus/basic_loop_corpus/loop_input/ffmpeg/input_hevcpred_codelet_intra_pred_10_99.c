#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

union __attribute__((packed)) __attribute__((may_alias)) unaligned_64 {
    uint64_t l;
};

int i;
int size = 32000000; // ~256MB of data (32M * 8 bytes per write) to target ~0.01 sec on modern CPU
uint16_t *left;
uint64_t pix = 0x123456789ABCDEF0ULL;

void init_vars() {
    left = aligned_alloc(64, (size + 4) * sizeof(uint16_t)); // Over-allocate to prevent overflow
    if (!left) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }
}