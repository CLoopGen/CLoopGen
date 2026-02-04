#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

#define DATA_SIZE_MB 64
#define TOTAL_ELEMENTS (DATA_SIZE_MB * (1 << 20) / sizeof(double))

double x[TOTAL_ELEMENTS];
size_t x_stride = 1;
size_t N = TOTAL_ELEMENTS - 100; // Ensure safe access with N-3 and i+1, N-1 indexing

double *delta;
double *gamma;
double *c;

size_t i;
size_t j;

void init_vars() {
    delta = malloc(N * sizeof(double));
    gamma = malloc(N * sizeof(double));
    c = malloc(N * sizeof(double));

    for (size_t idx = 0; idx < N; idx++) {
        delta[idx] = 1.0 + idx * 0.001;
        gamma[idx] = 0.5 + idx * 0.0005;
        c[idx] = idx * 2.0;
    }

    for (size_t idx = 0; idx < TOTAL_ELEMENTS; idx++) {
        x[idx] = 1.0;
    }
}