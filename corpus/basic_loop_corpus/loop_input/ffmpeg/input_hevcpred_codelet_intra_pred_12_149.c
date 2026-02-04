#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

union __attribute__((packed)) __attribute__((may_alias)) unaligned_64 {
    uint64_t l;
};

int i;
int size = 32 * 1024 * 1024; // 32M elements -> 64MB of uint16_t data
uint16_t *left;
uint64_t pix = 0x1111222233334444ULL;

void init_vars() {
    left = aligned_alloc(64, size * 2 * sizeof(uint16_t));
    if (!left) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
}