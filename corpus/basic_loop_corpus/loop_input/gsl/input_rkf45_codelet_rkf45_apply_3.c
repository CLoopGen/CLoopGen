#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <stdint.h>

#define DATA_SIZE_MB 64
#define TOTAL_ELEMENTS (DATA_SIZE_MB * (1 << 20) / sizeof(double))

double b5[4];
size_t dim;
double h;
double y[TOTAL_ELEMENTS];
size_t i;
double * k1;
double * k2;
double * k3;
double * k4;
double * ytmp;

void init_vars() {
    dim = TOTAL_ELEMENTS;
    h = 0.5;

    b5[0] = 0.1;
    b5[1] = 0.2;
    b5[2] = 0.3;
    b5[3] = 0.4;

    k1 = (double*)aligned_alloc(32, dim * sizeof(double));
    k2 = (double*)aligned_alloc(32, dim * sizeof(double));
    k3 = (double*)aligned_alloc(32, dim * sizeof(double));
    k4 = (double*)aligned_alloc(32, dim * sizeof(double));
    ytmp = (double*)aligned_alloc(32, dim * sizeof(double));

    for (size_t idx = 0; idx < dim; idx++) {
        y[idx] = (double)(idx % 1000) / 100.0;
        k1[idx] = (double)(idx % 7) + 1.0;
        k2[idx] = (double)(idx % 5) + 2.0;
        k3[idx] = (double)(idx % 3) + 3.0;
        k4[idx] = (double)(idx % 2) + 4.0;
        ytmp[idx] = 0.0;
    }
}