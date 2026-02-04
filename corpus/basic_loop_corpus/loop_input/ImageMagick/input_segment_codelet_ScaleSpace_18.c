#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

ssize_t *histogram;
double *scale_histogram;
double alpha;
double *gamma;
double sum;
ssize_t u;
ssize_t x;

void init_vars() {
    const size_t N = 256;
    const size_t gamma_size = 256;

    histogram = (ssize_t*)calloc(N, sizeof(ssize_t));
    scale_histogram = (double*)malloc(N * sizeof(double));
    gamma = (double*)malloc(gamma_size * sizeof(double));
    alpha = 1.5;

    for (size_t i = 0; i < N; i++) {
        histogram[i] = rand() % 1000;
    }
    for (size_t i = 0; i < gamma_size; i++) {
        gamma[i] = 1.0 / (1.0 + i);
    }
    sum = 0.0;
    u = 0;
    x = 0;
}