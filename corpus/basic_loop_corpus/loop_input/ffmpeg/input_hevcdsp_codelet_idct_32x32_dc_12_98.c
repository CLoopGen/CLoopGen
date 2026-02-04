#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int16_t *coeffs;
int i;
int j;
int coeff;

void init_vars() {
    const size_t total_elements = 32 * 32;
    const size_t data_size_bytes = total_elements * sizeof(int16_t);

    coeffs = (int16_t*)aligned_alloc(32, data_size_bytes);
    if (!coeffs) {
        exit(1);
    }

    for (size_t idx = 0; idx < total_elements; ++idx) {
        coeffs[idx] = 0;
    }

    i = 0;
    j = 0;
    coeff = 42;
}