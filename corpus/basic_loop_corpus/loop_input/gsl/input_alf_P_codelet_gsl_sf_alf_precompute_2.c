#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

size_t lmax = 2000;
size_t mmax = 1500;
double *alm;
double *sqrts;
size_t l;
size_t m;
size_t k = 0;

void init_vars() {
    const size_t alm_size = (lmax + 1) * (lmax + 1) * 2;
    const size_t sqrts_size = 2 * lmax + 10;

    alm = (double*)calloc(alm_size, sizeof(double));
    sqrts = (double*)malloc(sqrts_size * sizeof(double));

    for (size_t i = 0; i < sqrts_size; ++i) {
        sqrts[i] = sqrt((double)(i + 1));
    }
}