#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint32_t K;
uint32_t i;
uint32_t p;
uint32_t *row;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // ~64MB to ensure sufficient runtime (~0.01s)
    row = (uint32_t*)aligned_alloc(32, data_size);
    if (!row) exit(1);

    for (size_t idx = 0; idx < data_size / sizeof(uint32_t); idx++) {
        row[idx] = data_size / sizeof(uint32_t) - idx; // descending values
    }

    i = 1;
    K = data_size / sizeof(uint32_t) - 1;
    p = row[K];
}