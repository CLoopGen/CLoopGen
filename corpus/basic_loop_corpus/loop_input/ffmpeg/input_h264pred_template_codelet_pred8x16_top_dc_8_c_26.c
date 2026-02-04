#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

ptrdiff_t stride;
int i;
int dc0;
int dc1;
uint8_t *src;

void init_vars() {
    const size_t data_size = 1 << 20; // 1MB of data
    src = aligned_alloc(32, data_size);
    if (!src) {
        exit(1);
    }

    stride = 4;
    for (size_t idx = 0; idx < data_size; ++idx) {
        src[idx] = (uint8_t)(idx & 0xFF);
    }

    dc0 = 0;
    dc1 = 0;
}