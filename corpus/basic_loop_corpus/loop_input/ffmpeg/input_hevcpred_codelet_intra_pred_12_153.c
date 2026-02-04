#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

union __attribute__((packed)) __attribute__((may_alias)) unaligned_64 {
    uint64_t l;
};

int i;
int size = 32000000; // ~256MB of data: size * sizeof(uint16_t) * 2 (since we go up to 2*size)
uint16_t *top;
uint64_t pix = 0x123456789ABCDEF0ULL;

void init_vars() {
    top = (uint16_t*)aligned_alloc(8, (2 * size) * sizeof(uint16_t));
    if (!top) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
}