#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int16_t *coeffs;
int shift;
int x;
int y;
int size;

int16_t *original_coeffs_block = NULL;

void init_vars() {
    size = 8192;
    shift = 4;
    x = 0;
    y = 0;

    size_t num_elements = (size_t)size * size;
    original_coeffs_block = aligned_alloc(32, num_elements * sizeof(int16_t));
    if (!original_coeffs_block) {
        exit(1);
    }

    for (size_t i = 0; i < num_elements; i++) {
        original_coeffs_block[i] = (int16_t)(i % 32768);
    }

    coeffs = original_coeffs_block;
}