#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

float *coeffs;
float sum;

void init_vars() {
    const int size = 65536; // Adjusted for ~0.01 sec runtime
    coeffs = (float*)aligned_alloc(32, size * sizeof(float));
    if (!coeffs) {
        exit(1);
    }
    for (int i = 0; i < size; i++) {
        coeffs[i] = 1.0f + i * 0.1f;
    }
    sum = 10.0f;
}