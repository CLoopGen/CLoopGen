#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

double beta = 1.5;
int ldc;
int i;
int j;
int n1;
int n2;
double *C;

void init_vars() {
    n1 = 4096;
    n2 = 4096;
    ldc = n1;
    beta = 1.5;

    size_t size = (size_t)ldc * n2 * sizeof(double);
    C = (double*)aligned_alloc(32, size);
    if (!C) {
        exit(1);
    }

    for (int idx = 0; idx < n1 * n2; idx++) {
        C[idx] = 1.0;
    }
}