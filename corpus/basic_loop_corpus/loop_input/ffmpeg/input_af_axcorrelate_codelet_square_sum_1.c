#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

float *x;
float *y;
int size;
float square_sum;

void init_vars() {
    size = 65536 * 4;  // Approximately 1MB for two float arrays (each float is 4 bytes)

    x = (float*)aligned_alloc(32, size * sizeof(float));
    y = (float*)aligned_alloc(32, size * sizeof(float));

    for (int i = 0; i < size; i++) {
        x[i] = 1.0f + (i % 100);
        y[i] = 0.5f + (i % 75);
    }

    square_sum = 0.0f;
}