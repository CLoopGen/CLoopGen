#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int16_t *coeffs;
int i;
int j;
int coeff;

void init_vars() {
    coeffs = (int16_t*)aligned_alloc(32, sizeof(int16_t) * 4 * 4);
    if (!coeffs) exit(1);
    for (int idx = 0; idx < 16; idx++) {
        coeffs[idx] = 0;
    }
    i = 0;
    j = 0;
    coeff = 42;
}