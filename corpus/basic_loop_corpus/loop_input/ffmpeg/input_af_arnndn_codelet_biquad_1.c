#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

float *y;
float mem[2];
float *x;
float *b;
float *a;
int N;

void init_vars() {
    N = 1 << 20; // Approximately 1 million elements for ~0.01 sec runtime

    x = (float*)calloc(N, sizeof(float));
    y = (float*)calloc(N, sizeof(float));
    b = (float*)calloc(2, sizeof(float));
    a = (float*)calloc(2, sizeof(float));

    // Initialize coefficients
    b[0] = 1.0f;
    b[1] = 0.5f;
    a[0] = 0.2f;
    a[1] = 0.3f;

    // Initialize input signal
    for (int i = 0; i < N; i++) {
        x[i] = 1.0f; // Simple constant input
    }

    // Initialize memory
    mem[0] = 0.0f;
    mem[1] = 0.0f;
}