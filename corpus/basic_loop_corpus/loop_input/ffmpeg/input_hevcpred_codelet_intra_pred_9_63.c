#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

union __attribute__((packed)) __attribute__((may_alias)) unaligned_64 {
    uint64_t l;
};

int i;
int size = 32 * 1024 * 1024; // ~256 MB of uint16_t data (size in units for 2*size loop iterations)
uint16_t *left;
uint64_t pix = 0x1111222233334444ULL;

void init_vars() {
    left = (uint16_t*)aligned_alloc(8, (2 * size) * sizeof(uint16_t));
    if (!left) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
}