#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int N;
double *C;
int ldc;
int i;
int j;

void init_vars() {
    N = 2048;
    ldc = N;
    C = (double*)aligned_alloc(32, sizeof(double) * N * ldc);
}

__attribute__((destructor))
void cleanup() {
    if (C) free(C);
}