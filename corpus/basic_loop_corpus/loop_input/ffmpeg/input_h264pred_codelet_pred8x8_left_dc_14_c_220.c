#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

ptrdiff_t stride;
int i;
int dc0;
int dc2;
uint16_t *src;

void init_vars() {
    const size_t data_size = 1 << 20; // 1MB of data: 524,288 elements
    src = (uint16_t *)aligned_alloc(32, data_size * sizeof(uint16_t));
    if (!src) exit(1);

    stride = 131072; // Ensures safe access with offset -1 and up to (i+4)*stride where i < 4

    for (size_t idx = 0; idx < data_size; ++idx) {
        src[idx] = (uint16_t)(idx & 0xFFFF);
    }

    dc0 = 0;
    dc2 = 0;
}