#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int16_t *coeffs;
int x;
int y;
int size;

static int16_t *coeffs_buffer;
static ptrdiff_t buffer_size;

void init_vars() {
    size = 8192; 
    buffer_size = (size + 2) * size * sizeof(int16_t);
    coeffs_buffer = (int16_t*)calloc(buffer_size / sizeof(int16_t), sizeof(int16_t));
    if (!coeffs_buffer) {
        exit(1);
    }
    coeffs = coeffs_buffer + size; 

    for (ptrdiff_t i = 0; i < buffer_size / sizeof(int16_t); ++i) {
        coeffs_buffer[i] = rand() % 100;
    }
}