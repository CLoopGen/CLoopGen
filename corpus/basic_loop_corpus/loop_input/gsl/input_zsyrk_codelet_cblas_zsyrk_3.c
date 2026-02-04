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
    beta_real = 0.8;
    beta_imag = 0.6;
    N = 2048;
    ldc = N;
    size_t total_elements = (size_t)N * (size_t)ldc;
    size_t total_bytes = total_elements * 2 * sizeof(double);
    C = aligned_alloc(32, total_bytes);
    if (!C) {
        exit(1);
    }
    double *C_ptr = (double *)C;
    for (size_t idx = 0; idx < total_elements * 2; idx++) {
        C_ptr[idx] = (double)(idx % 127) / 10.0;
    }
}