#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int16_t *coeffs;
int i;
int j;
int coeff;

void init_vars() {
    const size_t total_size = 4 * 4 * sizeof(int16_t);
    coeffs = aligned_alloc(32, total_size);
    for (size_t idx = 0; idx < 4 * 4; idx++) {
        coeffs[idx] = 0;
    }
    i = 0;
    j = 0;
    coeff = 42;
}