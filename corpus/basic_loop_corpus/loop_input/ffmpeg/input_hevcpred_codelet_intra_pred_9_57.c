#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

union __attribute__((packed)) __attribute__((may_alias)) unaligned_64 {
    uint64_t l;
};

int i;
int size = 32768; // Ensures loop runs ~0.01s, 32k * 2 (due to left + size offset) = 65536 elements
uint16_t *left;
uint64_t pix = 0xCAFEBABEDEADBEEFULL;

void init_vars() {
    left = aligned_alloc(16, sizeof(uint16_t) * (size * 2));
    if (!left) {
        exit(1);
    }
    for (int j = 0; j < size * 2; ++j) {
        left[j] = (uint16_t)(j & 0xFFFF);
    }
    pix = 0xCAFEBABEDEADBEEFULL;
    i = 0;
}