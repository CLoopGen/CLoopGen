#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int N = 2048;
double beta = 1.5;

int ldc = 2048;
int i, j;

double *C_data;
void *C;

void init_vars() {
    size_t total_elements = ldc * N;
    size_t total_bytes = 2 * total_elements * sizeof(double); // complex-like: real and imaginary parts

    C_data = (double *)aligned_alloc(32, total_bytes);
    if (!C_data) {
        exit(1);
    }
    C = (void *)C_data;

    for (size_t idx = 0; idx < 2 * total_elements; ++idx) {
        C_data[idx] = 1.0;
    }

    N = 2048;
    beta = 1.5;
    ldc = 2048;
    i = 0;
    j = 0;
}