#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

union __attribute__((packed)) __attribute__((may_alias)) unaligned_64 {
    uint64_t l;
};

int i;
int size;
uint16_t *left;
uint64_t pix;

void init_vars() {
    size = 32 * 1024 * 1024; // 64 MB of uint16_t data (128 MB total memory), aiming for ~0.01s runtime
    left = (uint16_t*)aligned_alloc(64, size * sizeof(uint16_t));
    if (!left) exit(1);
    pix = 0x123456789ABCDEF0ULL;
    i = 0;
}

__attribute__((destructor))
void cleanup() {
    free(left);
}