#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int16_t *coeffs;
int i;
int j;
int coeff;

void init_vars() {
    coeffs = (int16_t*)calloc(32 * 32, sizeof(int16_t));
    if (!coeffs) {
        exit(1);
    }
    i = 0;
    j = 0;
    coeff = 42;
}