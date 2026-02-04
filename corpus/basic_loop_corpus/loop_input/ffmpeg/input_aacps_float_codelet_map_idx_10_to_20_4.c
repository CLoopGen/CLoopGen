#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int8_t *par_mapped;
int8_t *par;
int b;

void init_vars() {
    size_t data_size = 64 * 1024 * 1024; // ~64MB of input data for ~0.01s runtime estimate

    par = (int8_t*)aligned_alloc(32, data_size);
    par_mapped = (int8_t*)aligned_alloc(32, 2 * data_size);

    if (!par || !par_mapped) {
        exit(1);
    }

    for (size_t i = 0; i < data_size; i++) {
        par[i] = (int8_t)(i & 0xFF);
    }

    for (size_t i = 0; i < 2 * data_size; i++) {
        par_mapped[i] = 0;
    }

    b = (int)data_size - 1;
}