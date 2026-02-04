#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int16_t *coeffs;
int i;
int j;
int coeff;

void init_vars() {
    const size_t data_size = 1 << 20; // 1MB of data
    coeffs = aligned_alloc(32, data_size);
    if (!coeffs) {
        exit(1);
    }
    for (size_t idx = 0; idx < data_size / sizeof(int16_t); idx++) {
        coeffs[idx] = 0;
    }
    i = 0;
    j = 0;
    coeff = 42;
}