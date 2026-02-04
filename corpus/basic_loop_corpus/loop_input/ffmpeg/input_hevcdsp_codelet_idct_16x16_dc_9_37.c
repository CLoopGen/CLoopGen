#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int16_t *coeffs;
int i;
int j;
int coeff;

void init_vars() {
    const size_t data_size = 16 * 16 * sizeof(int16_t);
    coeffs = aligned_alloc(32, data_size);
    for (size_t idx = 0; idx < 16 * 16; idx++) {
        coeffs[idx] = 0;
    }
    i = 0;
    j = 0;
    coeff = 42;
}