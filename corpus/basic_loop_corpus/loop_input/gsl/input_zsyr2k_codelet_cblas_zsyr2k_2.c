#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

int N;
void *C;
int ldc;
int i;
int j;
double beta_real;
double beta_imag;

void init_vars() {
    beta_real = 0.5;
    beta_imag = 0.3;
    N = 2048;
    ldc = N;
    C = aligned_alloc(32, 2 * ldc * N * sizeof(double));
}

__attribute__((destructor))
void cleanup() {
    if (C) free(C);
}