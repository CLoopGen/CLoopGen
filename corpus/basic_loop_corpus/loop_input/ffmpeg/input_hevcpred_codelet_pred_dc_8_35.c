#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

union __attribute__((packed)) __attribute__((may_alias)) unaligned_32 {
    uint32_t l;
};

ptrdiff_t stride;
int i;
int j;
int size;
uint8_t *src;
uint32_t a;

void init_vars() {
    size = 4096;  // ~64 MB of data (size x size), sufficient for ~0.01 sec on modern CPU
    stride = size;
    a = 0xDEADBEEF;

    src = aligned_alloc(64, (size_t)stride * size);
    if (!src) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }
}