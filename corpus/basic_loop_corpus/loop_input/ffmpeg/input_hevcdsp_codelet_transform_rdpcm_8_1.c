#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int16_t *coeffs;
int x;
int y;
int size;

static int16_t *coeffs_storage;
static ptrdiff_t coeffs_offset;

void init_vars() {
    size = 8192;
    coeffs_offset = size;
    coeffs_storage = aligned_alloc(32, sizeof(int16_t) * size * (size + 1));
    if (!coeffs_storage) {
        exit(1);
    }
    for (int i = 0; i < size * (size + 1); i++) {
        coeffs_storage[i] = rand() % 100;
    }
    coeffs = coeffs_storage + coeffs_offset;
}

__attribute__((destructor))
static void cleanup() {
    if (coeffs_storage) {
        free(coeffs_storage);
    }
}