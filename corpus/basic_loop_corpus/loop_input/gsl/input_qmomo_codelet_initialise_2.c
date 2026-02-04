#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

double *ri;
double *rg;
double alpha_p1;
double alpha_p2;
size_t i;
double an;
double anm1;

void init_vars() {
    const size_t data_size = 256 * 1024 * 1024; // ~256MB total data
    const size_t array_size = data_size / sizeof(double) / 2; // Two arrays

    ri = (double*)calloc(array_size, sizeof(double));
    rg = (double*)calloc(array_size, sizeof(double));

    alpha_p1 = 1.5;
    alpha_p2 = 0.8;
    an = 2.0;
    anm1 = 1.0;

    for (size_t idx = 0; idx < array_size; idx++) {
        ri[idx] = (double)(idx % 100) / 100.0;
        rg[idx] = 0.0;
    }

    i = 2;
}