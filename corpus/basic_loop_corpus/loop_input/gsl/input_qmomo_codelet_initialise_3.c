#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

double *rj;
double *rh;
double beta_p1;
double beta_p2;
size_t i;
double an;
double anm1;

void init_vars() {
    const size_t array_size = 256 * (1 << 20) / sizeof(double); // ~256MB total data
    rj = (double*)calloc(array_size, sizeof(double));
    rh = (double*)calloc(array_size, sizeof(double));

    beta_p1 = 1.5;
    beta_p2 = 0.8;
    an = 2.0;
    anm1 = 1.0;

    for (size_t idx = 0; idx < array_size; idx++) {
        rj[idx] = (double)(idx % 100) / 10.0;
        rh[idx] = (double)(idx % 50) / 20.0;
    }
}