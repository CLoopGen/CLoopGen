#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

float *x;
float *window;
int overlap;
int n;
float xx[864];

void init_vars() {
    n = 864;
    overlap = 864 / 2;

    x = (float*)aligned_alloc(32, n * sizeof(float));
    window = (float*)aligned_alloc(32, overlap * sizeof(float));

    for (int i = 0; i < n; i++) {
        x[i] = 1.0f + (i % 100) * 0.01f;
    }
    for (int i = 0; i < overlap; i++) {
        window[i] = 0.5f + (i % 50) * 0.01f;
    }
}