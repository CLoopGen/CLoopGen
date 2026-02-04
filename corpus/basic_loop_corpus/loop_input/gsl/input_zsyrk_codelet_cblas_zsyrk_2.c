#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int N;
void *C;
int ldc;
int i;
int j;
double beta_real;
double beta_imag;

void init_vars() {
    beta_real = 2.0;
    beta_imag = 1.0;

    N = 2048;
    ldc = N;

    size_t total_elements = N * ldc;
    size_t total_bytes = 2 * total_elements * sizeof(double);

    C = aligned_alloc(32, total_bytes);
    if (!C) {
        exit(1);
    }

    double *C_ptr = (double *)C;
    for (size_t idx = 0; idx < 2 * total_elements; ++idx) {
        C_ptr[idx] = (double)(idx % 127);
    }
}