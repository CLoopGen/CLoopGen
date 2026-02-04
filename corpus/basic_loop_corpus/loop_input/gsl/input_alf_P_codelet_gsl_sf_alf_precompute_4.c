#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

size_t lmax = 2000;
size_t mmax = 1000;
double *alm;
double *sqrts;
size_t l = 0;
size_t m = 0;
size_t k = 0;

void init_vars() {
    const size_t alm_size = 4 * (lmax + 1) * (mmax + 1);
    const size_t sqrts_size = 2 * lmax + 2;

    alm = (double*)calloc(alm_size, sizeof(double));
    sqrts = (double*)calloc(sqrts_size, sizeof(double));

    for (size_t i = 0; i < sqrts_size; ++i) {
        sqrts[i] = sqrt((double)(i + 1));
    }

    k = 0;
}