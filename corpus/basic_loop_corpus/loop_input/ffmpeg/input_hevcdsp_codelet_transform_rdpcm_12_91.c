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
    storage_size = (ptrdiff_t)size * (size + 1);
    coeffs_storage = (int16_t*)calloc(storage_size, sizeof(int16_t));
    if (!coeffs_storage) {
        exit(1);
    }

    for (ptrdiff_t i = 0; i < storage_size; i++) {
        coeffs_storage[i] = (int16_t)(i & 0xFF);
    }

    coeffs = coeffs_storage + size;
}