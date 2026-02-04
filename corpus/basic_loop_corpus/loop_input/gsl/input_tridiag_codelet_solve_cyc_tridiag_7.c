#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <math.h>

size_t N;
double *delta;
double *alpha;
size_t i;
double sum;

void init_vars() {
    N = 25000000; 

    alpha = (double*)aligned_alloc(32, N * sizeof(double));
    delta = (double*)aligned_alloc(32, N * sizeof(double));

    for (size_t idx = 0; idx < N; idx++) {
        alpha[idx] = (double)(idx % 123) + 1.0;
        delta[idx] = (double)(idx % 456) - 228.0;
    }

    i = 0;
    sum = 0.0;
}