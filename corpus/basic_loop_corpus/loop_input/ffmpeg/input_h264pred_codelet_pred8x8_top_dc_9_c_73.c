#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

ptrdiff_t stride;
int i;
int dc0;
int dc1;
uint16_t *src;

void init_vars() {
    const size_t data_size = 131072; // 256KB of uint16_t (131072 elements)
    src = (uint16_t*)aligned_alloc(32, data_size * sizeof(uint16_t));
    if (!src) exit(1);

    for (size_t idx = 0; idx < data_size; ++idx) {
        src[idx] = (uint16_t)(idx & 0xFFFF);
    }

    stride = 2;
    i = 0;
    dc0 = 0;
    dc1 = 0;
}