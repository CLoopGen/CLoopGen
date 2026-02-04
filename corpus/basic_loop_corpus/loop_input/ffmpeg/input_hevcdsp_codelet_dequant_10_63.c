#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int16_t *coeffs;
int shift;
int x;
int y;
int size;
int offset;

void init_vars() {
    size = 8192;
    shift = 1;
    offset = 1;
    coeffs = (int16_t*)aligned_alloc(32, size * size * sizeof(int16_t));
    for (int i = 0; i < size * size; i++) {
        coeffs[i] = (int16_t)(i % 32767);
    }
}