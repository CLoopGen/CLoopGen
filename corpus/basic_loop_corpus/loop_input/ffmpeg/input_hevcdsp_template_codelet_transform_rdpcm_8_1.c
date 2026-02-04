#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int16_t *coeffs;
int x;
int y;
int size;

static int16_t *coeffs_storage;
static ptrdiff_t storage_size;

void init_vars() {
    size = 8192;
    storage_size = (size + 1) * size * sizeof(int16_t);
    coeffs_storage = aligned_alloc(64, storage_size);
    if (!coeffs_storage) exit(1);

    for (ptrdiff_t i = 0; i < storage_size / sizeof(int16_t); i++) {
        coeffs_storage[i] = rand() % 100;
    }

    coeffs = coeffs_storage + size;
}