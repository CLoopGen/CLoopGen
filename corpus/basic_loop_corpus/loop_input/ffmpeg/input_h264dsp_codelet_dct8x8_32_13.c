#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

static int32_t *coef_storage;
int32_t *coef;
int x;
int y;

void init_vars() {
    size_t data_size = 1 << 24; // ~16.7 million elements, roughly 64MB for int32_t
    coef_storage = (int32_t*)aligned_alloc(32, data_size * sizeof(int32_t));
    if (!coef_storage) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }
    coef = coef_storage;

    for (size_t i = 0; i < data_size; i++) {
        coef[i] = rand() % 1000 - 500;
    }

    x = 0;
    y = 0;
}