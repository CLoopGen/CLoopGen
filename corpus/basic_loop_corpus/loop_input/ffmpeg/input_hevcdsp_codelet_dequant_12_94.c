#include <stdint.h>
#include <stdlib.h>

int16_t *coeffs;
int shift;
int x;
int y;
int size;

void init_vars() {
    size = 8192;
    shift = 2;
    x = 0;
    y = 0;

    coeffs = aligned_alloc(32, size * size * sizeof(int16_t));
    if (!coeffs) exit(1);
}