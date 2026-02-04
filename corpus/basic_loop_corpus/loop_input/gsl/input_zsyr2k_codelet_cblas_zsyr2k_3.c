#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int N = 1024;
int ldc = 1024;
int i, j;
double beta_real = 1.5;
double beta_imag = 0.8;
void *C;

void init_vars() {
    const size_t total_size = 2 * ldc * N * sizeof(double);
    C = aligned_alloc(32, total_size);
    if (!C) {
        exit(1);
    }
    for (size_t idx = 0; idx < 2 * ldc * N; ++idx) {
        ((double *)C)[idx] = (double)(idx % 127) / 10.0;
    }
}