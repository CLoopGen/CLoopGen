#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

union __attribute__((packed)) __attribute__((may_alias)) unaligned_64 {
    uint64_t l;
};

int i;
int size = 32768; // Ensures loop runs ~0.01s with 4-byte steps (131072 bytes accessed)
uint16_t *left;

uint64_t pix = 0xCAFEBABEDEADBEEFULL;

void init_vars() {
    left = aligned_alloc(8, (size + size) * sizeof(uint16_t)); // Allocate extra space to prevent overflow when accessing left + size + i
    if (!left) exit(1);
}