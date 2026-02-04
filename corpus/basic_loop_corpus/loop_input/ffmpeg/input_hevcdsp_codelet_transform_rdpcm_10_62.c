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
    coeffs = coeffs_data;

    for (int i = 0; i < size * size; i++) {
        coeffs_data[i] = rand() % 1000;
    }

    x = 0;
    y = 0;
}