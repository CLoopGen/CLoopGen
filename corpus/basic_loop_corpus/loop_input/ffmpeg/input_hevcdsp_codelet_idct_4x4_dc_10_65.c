#include <inttypes.h>
#include <stdlib.h>

int16_t *coeffs;
int i;
int j;
int coeff;

void init_vars() {
    coeffs = (int16_t*)aligned_alloc(16, sizeof(int16_t) * 4 * 4);
    coeff = 42;
}

__attribute__((destructor))
static void cleanup() {
    free(coeffs);
}