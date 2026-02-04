#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

union __attribute__((packed)) __attribute__((may_alias)) unaligned_64 {
    uint64_t l;
};

int i;
int size;
uint16_t *top;
uint64_t pix;

void init_vars() {
    size = 32 * 1024 * 1024; // 64 MB of data (32M uint16_t elements = 64MB)
    top = aligned_alloc(64, size * sizeof(uint16_t));
    if (!top) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }
    pix = 0x1122334455667788ULL;
    i = 0;
}

__attribute__((destructor))
void cleanup() {
    free(top);
}