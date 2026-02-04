#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

union __attribute__((packed)) __attribute__((may_alias)) unaligned_64 {
    uint64_t l;
};

int i;
int size = 32000000; // Ensures loop runs ~0.01 sec (approx 32M iterations, 4 steps per iteration -> 128M bytes written)
uint16_t *left;
uint64_t pix = 0x123456789ABCDEF0ULL;

void init_vars() {
    left = aligned_alloc(64, (size + size) * sizeof(uint16_t));
    if (!left) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }
}