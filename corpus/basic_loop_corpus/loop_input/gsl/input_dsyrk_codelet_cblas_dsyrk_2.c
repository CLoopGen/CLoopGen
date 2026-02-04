#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int N;
double beta;
double *C;
int ldc;
int i;
int j;

void init_vars() {
    N = 2048;
    beta = 1.5;
    ldc = N;
    C = (double *)aligned_alloc(32, sizeof(double) * N * N);
    for (int idx = 0; idx < N * N; idx++) {
        C[idx] = 1.0;
    }
}