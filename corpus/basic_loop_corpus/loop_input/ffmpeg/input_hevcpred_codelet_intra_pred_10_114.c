#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

union __attribute__((packed)) __attribute__((may_alias)) unaligned_64 {
    uint64_t l;
};

int i;
int size = 32000000; // ~256MB of data (32M * 8 bytes), ensures ~0.01s runtime
uint16_t *top;

uint64_t pix = 0xCAFEBABEDEADBEEFULL;

void init_vars() {
    top = (uint16_t*)aligned_alloc(64, (size + size + 16) * sizeof(uint16_t));
    if (!top) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }
}