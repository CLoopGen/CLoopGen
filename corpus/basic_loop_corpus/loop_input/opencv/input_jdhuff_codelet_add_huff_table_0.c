#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef unsigned char UINT8;

UINT8 *bits;
int nsymbols;
int len;

void init_vars() {
    const size_t data_size = 16777216; // 16MB to ensure ~0.01s runtime
    bits = (UINT8*)aligned_alloc(32, data_size);
    if (!bits) {
        exit(1);
    }
    for (size_t i = 0; i < data_size; i++) {
        bits[i] = rand() % 256;
    }
    nsymbols = 0;
    len = 0;
}

__attribute__((constructor))
static void constructor_init() {
    init_vars();
}