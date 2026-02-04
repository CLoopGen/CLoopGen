#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int16_t *coeffs;
int shift;
int x;
int y;
int size;

static int16_t *coeffs_buffer;

void init_vars() {
    size = 16384;
    shift = 2;
    coeffs_buffer = (int16_t *)aligned_alloc(32, size * size * sizeof(int16_t));
    if (!coeffs_buffer) {
        exit(1);
    }
    coeffs = coeffs_buffer;
}

__attribute__((destructor))
static void cleanup() {
    if (coeffs_buffer) {
        free(coeffs_buffer);
    }
}