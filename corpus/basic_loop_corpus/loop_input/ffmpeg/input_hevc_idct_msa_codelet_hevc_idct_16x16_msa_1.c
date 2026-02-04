#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int16_t gt16x16_cnst[64] __attribute__((aligned(64))) = {0};

static int16_t coeffs_data[256 * 1024]; // ~512KB buffer for coeffs
int16_t *coeffs = coeffs_data;

int16_t i;
int16_t j;
int16_t k;
int16_t *buf_ptr;
int16_t *src;
int16_t *filter;

void init_vars() {
    // Initialize pointers and variables to valid states
    src = (int16_t*)malloc(256 * 1024 * sizeof(int16_t));
    if (!src) exit(1);

    buf_ptr = coeffs + 8; // As assigned in loop
    filter = &gt16x16_cnst[0];

    // Initialize gt16x16_cnst with non-zero values to avoid trivial optimization
    for (int idx = 0; idx < 64; idx++) {
        gt16x16_cnst[idx] = (int16_t)(idx * idx - 3 * idx + 2);
    }

    // Initialize large buffers with sample data
    for (size_t idx = 0; idx < 256 * 1024; idx++) {
        coeffs_data[idx] = (int16_t)(idx % 32767);
        src[idx] = (int16_t)((idx + 100) % 32767);
    }
}