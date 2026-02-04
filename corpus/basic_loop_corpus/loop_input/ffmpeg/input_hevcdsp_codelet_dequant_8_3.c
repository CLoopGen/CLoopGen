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

static int16_t *coeffs_data;

void init_vars() {
    size = 8192;
    shift = 1;
    offset = 1;
    coeffs_data = (int16_t*)aligned_alloc(32, size * size * sizeof(int16_t));
    if (!coeffs_data) {
        exit(1);
    }
    for (int i = 0; i < size * size; i++) {
        coeffs_data[i] = (int16_t)(i & 0x7FF);
    }
    coeffs = coeffs_data;
}

void cleanup_vars() {
    if (coeffs_data) {
        free(coeffs_data);
    }
}