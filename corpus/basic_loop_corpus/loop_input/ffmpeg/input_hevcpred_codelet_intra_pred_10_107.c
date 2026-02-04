#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

union __attribute__((packed)) __attribute__((may_alias)) unaligned_64 {
    uint64_t l;
};

int i;
int size = 32 * 1024 * 1024; // 32M elements -> ~256MB for uint16_t array, ensures ~0.01s runtime
uint16_t *left;
uint64_t pix = 0x123456789ABCDEF0ULL;

void init_vars() {
    left = (uint16_t*)aligned_alloc(8, size * 2 * sizeof(uint16_t));
    if (!left) {
        exit(1);
    }
}