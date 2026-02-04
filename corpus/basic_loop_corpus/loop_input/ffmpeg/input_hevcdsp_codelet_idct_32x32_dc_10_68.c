#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int16_t *coeffs;
int i;
int j;
int coeff;

void init_vars() {
    coeff = 42;
    coeffs = (int16_t*)calloc(32 * 32, sizeof(int16_t));
}