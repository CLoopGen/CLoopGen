#include <stdlib.h>
#include <stdint.h>

int16_t *coeffs;
int i;
int j;
int coeff;

void init_vars() {
    coeffs = (int16_t*)calloc(32 * 32, sizeof(int16_t));
    i = 0;
    j = 0;
    coeff = 42;
}