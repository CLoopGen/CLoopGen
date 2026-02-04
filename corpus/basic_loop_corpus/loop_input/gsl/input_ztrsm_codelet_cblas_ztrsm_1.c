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

    size_t total_elements = n1 * ldb;
    size_t total_bytes = 2 * total_elements * sizeof(double);
    B = aligned_alloc(32, total_bytes);
    if (!B) {
        exit(1);
    }

    double *B_ptr = (double *)B;
    for (size_t idx = 0; idx < 2 * total_elements; ++idx) {
        B_ptr[idx] = (double)(idx % 127) / 10.0;
    }
}