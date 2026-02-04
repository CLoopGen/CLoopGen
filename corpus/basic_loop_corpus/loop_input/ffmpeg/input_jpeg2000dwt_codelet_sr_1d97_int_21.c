#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int32_t *p;
int i0;
int i1;
int i;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // ~64MB of int32_t data
    p = (int32_t*)aligned_alloc(32, data_size);
    if (!p) {
        exit(1);
    }

    for (size_t idx = 0; idx < data_size / sizeof(int32_t); ++idx) {
        p[idx] = (int32_t)(idx % 1000);
    }

    i0 = 2;
    i1 = (data_size / sizeof(int32_t)) - 4;
}