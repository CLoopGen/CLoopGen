#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

void *B;
int ldb;
int i;
int j;
int n1;
int n2;
double alpha_real;
double alpha_imag;

void init_vars() {
    alpha_real = 1.5;
    alpha_imag = 0.8;
    n1 = 4096;
    n2 = 4096;
    ldb = n2;

    size_t total_elements = (size_t)ldb * n1;
    size_t total_bytes = total_elements * 2 * sizeof(double);

    B = aligned_alloc(32, total_bytes);
    if (!B) {
        exit(1);
    }

    double *B_d = (double *)B;
    for (size_t idx = 0; idx < total_elements * 2; idx++) {
        B_d[idx] = (double)(idx % 127) / 10.0;
    }
}