#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct {
    double *scratch;
    size_t n;
} gsl_wavelet_workspace;

double *a;
size_t stride;
size_t n;
gsl_wavelet_workspace *work;
size_t i;

void init_vars() {
    n = 16777216; // 16M elements, ~128MB of data (16M * sizeof(double) = 128MB)
    stride = 1;
    a = (double*)aligned_alloc(32, n * stride * sizeof(double));
    work = (gsl_wavelet_workspace*)malloc(sizeof(gsl_wavelet_workspace));
    work->n = n;
    work->scratch = (double*)aligned_alloc(32, n * sizeof(double));

    for (size_t j = 0; j < n; j++) {
        work->scratch[j] = (double)(j + 1) * 0.5;
    }

    for (size_t j = 0; j < n * stride; j++) {
        a[j] = 0.0;
    }
}