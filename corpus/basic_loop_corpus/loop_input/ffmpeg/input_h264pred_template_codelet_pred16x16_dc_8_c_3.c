#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

ptrdiff_t stride = 16;
int i;
int dc = 0;
uint8_t *src;

void init_vars() {
    const size_t data_size = 16777216; // 16 MB
    src = (uint8_t *)aligned_alloc(32, data_size);
    if (!src) {
        exit(1);
    }
    for (size_t idx = 0; idx < data_size; idx++) {
        src[idx] = (uint8_t)(idx & 0xFF);
    }
    stride = 16;
    dc = 0;
}