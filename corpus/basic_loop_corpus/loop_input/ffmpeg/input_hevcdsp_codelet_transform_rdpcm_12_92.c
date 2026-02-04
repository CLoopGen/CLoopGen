#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int16_t *coeffs;
int x;
int y;
int size;

static int16_t *coeffs_storage;
static ptrdiff_t coeffs_stride;

void init_vars() {
    size = 8192;
    coeffs_stride = size * sizeof(int16_t);

    coeffs_storage = aligned_alloc(64, (size_t)size * size * sizeof(int16_t));
    if (!coeffs_storage) {
        exit(1);
    }

    for (int i = 0; i < size * size; i++) {
        coeffs_storage[i] = (int16_t)(i % 32767);
    }

    coeffs = coeffs_storage;
}