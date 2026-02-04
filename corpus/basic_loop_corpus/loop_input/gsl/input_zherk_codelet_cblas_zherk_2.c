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
    C_data = (double*)aligned_alloc(32, sizeof(double) * 2 * ldc * N);
    if (!C_data) {
        exit(1);
    }
    C = (void*)C_data;

    for (int idx = 0; idx < 2 * ldc * N; idx++) {
        C_data[idx] = (double)(idx % 127);
    }

    N = 2048;
    ldc = 2048;
    beta = 1.5;
}