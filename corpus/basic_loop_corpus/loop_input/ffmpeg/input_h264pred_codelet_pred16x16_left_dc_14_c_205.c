#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

ptrdiff_t stride;
int i;
int dc;
uint16_t *src;

void init_vars() {
    const size_t total_size = 1 << 20; // 1MB of data
    src = aligned_alloc(32, total_size * sizeof(uint16_t));
    if (!src) {
        exit(1);
    }

    for (size_t idx = 0; idx < total_size; ++idx) {
        src[idx] = rand() & 0xFFFF;
    }

    stride = 64; 
    dc = 0;
}