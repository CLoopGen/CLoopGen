#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int N = 1 << 24; // 256M elements, adjust for ~0.01s runtime
void *Y;
int incY = 1;
int i = 0;
double beta_real = 1.5;
double beta_imag = 0.8;
int iy = 0;

void init_vars() {
    Y = aligned_alloc(32, 2 * N * sizeof(double));
    if (!Y) {
        exit(1);
    }
    double *y_ptr = (double *)Y;
    for (int idx = 0; idx < 2 * N; idx++) {
        y_ptr[idx] = (double)(idx % 127) / 10.0;
    }
}