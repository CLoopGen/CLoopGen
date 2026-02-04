#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

void *C;
int ldc;
int i;
int j;
int n1;
int n2;
double beta_real;
double beta_imag;

void init_vars() {
    beta_real = 0.8;
    beta_imag = 0.6;
    n1 = 2048;
    n2 = 4096;
    ldc = n2;

    size_t total_elements = ldc * n1;
    size_t total_bytes = 2 * total_elements * sizeof(double);
    C = aligned_alloc(32, total_bytes);
    if (!C) {
        exit(1);
    }

    double *C_dbl = (double *)C;
    for (size_t idx = 0; idx < 2 * total_elements; ++idx) {
        C_dbl[idx] = (double)(idx % 127) / 127.0;
    }
}