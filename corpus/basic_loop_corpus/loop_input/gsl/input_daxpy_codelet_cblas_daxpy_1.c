#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int N;
double alpha;
double *X;
double *Y;
int i;
int m;

void init_vars() {
    N = 1 << 24; // 16 million elements, roughly 128MB for two arrays of double
    alpha = 1.5;
    X = (double *)aligned_alloc(32, N * sizeof(double));
    Y = (double *)aligned_alloc(32, N * sizeof(double));

    for (int j = 0; j < N; j++) {
        X[j] = (double)(j % 100) + 1.0;
        Y[j] = (double)(j % 50) + 2.0;
    }

    m = 0;
}

// Ensure weak or external definition compatibility
__attribute__((weak)) void loop();

// Allow linking with external loop function without main