#include <inttypes.h>
#include <stdlib.h>

int16_t *coeffs;
int i;
int j;
int coeff;

void init_vars() {
    coeffs = (int16_t*)aligned_alloc(16, 8 * 8 * sizeof(int16_t));
    coeff = 42;
}