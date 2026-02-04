#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int16_t *coeffs;
int x;
int y;
int size;

static int16_t *coeffs_data;
static ptrdiff_t coeffs_stride;

void init_vars() {
    size = 8192;
    coeffs_stride = size * sizeof(int16_t);

    coeffs_data = aligned_alloc(32, (size_t)size * size * sizeof(int16_t));
    if (!coeffs_data) {
        exit(1);
    }

    for (int i = 0; i < size * size; i++) {
        coeffs_data[i] = (int16_t)(i % 32767);
    }

    coeffs = coeffs_data;
}