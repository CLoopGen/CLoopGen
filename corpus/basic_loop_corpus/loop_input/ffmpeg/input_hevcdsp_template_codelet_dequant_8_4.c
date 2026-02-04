#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int16_t *coeffs;
int shift;
int x;
int y;
int size;

void init_vars() {
    size = 8192;
    shift = 2;
    coeffs = (int16_t *)aligned_alloc(16, size * size * sizeof(int16_t));
    if (!coeffs) {
        exit(1);
    }
    for (int i = 0; i < size * size; i++) {
        coeffs[i] = (int16_t)(i % 32768);
    }
}