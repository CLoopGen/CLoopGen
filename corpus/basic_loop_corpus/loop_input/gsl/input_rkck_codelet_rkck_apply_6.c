#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

#define DATA_SIZE_MB 64
#define TOTAL_ELEMENTS (DATA_SIZE_MB * (1 << 20) / sizeof(double))

double ec[7];
size_t dim;
double h;
double yerr[TOTAL_ELEMENTS];
size_t i;
double * k1;
double * k3;
double * k4;
double * k5;
double * k6;

void init_vars() {
    dim = TOTAL_ELEMENTS;
    h = 0.5;

    ec[0] = 0.0;
    ec[1] = 1.0 / 5.0;
    ec[2] = 0.0;
    ec[3] = 2.0 / 5.0;
    ec[4] = 3.0 / 5.0;
    ec[5] = 1.0 / 2.0;
    ec[6] = 1.0;

    k1 = (double*)aligned_alloc(32, dim * sizeof(double));
    k3 = (double*)aligned_alloc(32, dim * sizeof(double));
    k4 = (double*)aligned_alloc(32, dim * sizeof(double));
    k5 = (double*)aligned_alloc(32, dim * sizeof(double));
    k6 = (double*)aligned_alloc(32, dim * sizeof(double));

    for (size_t idx = 0; idx < dim; idx++) {
        k1[idx] = 1.0 + idx * 0.000001;
        k3[idx] = 1.5 + idx * 0.000001;
        k4[idx] = 2.0 + idx * 0.000001;
        k5[idx] = 2.5 + idx * 0.000001;
        k6[idx] = 3.0 + idx * 0.000001;
        yerr[idx] = 0.0;
    }
}