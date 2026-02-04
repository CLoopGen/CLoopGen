#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

union __attribute__((packed)) __attribute__((may_alias)) unaligned_64 {
    uint64_t l;
};

ptrdiff_t stride;
int i;
int j;
int size;
uint16_t *src;
uint64_t a;

void init_vars() {
    size = 4096; 
    stride = size;
    a = 0x123456789ABCDEF0ULL;

    src = aligned_alloc(64, sizeof(uint16_t) * size * (size + 4));
    if (!src) {
        exit(1);
    }
}