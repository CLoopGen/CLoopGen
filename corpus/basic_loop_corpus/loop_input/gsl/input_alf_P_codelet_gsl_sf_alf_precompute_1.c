#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

size_t lmax;
size_t mmax;
double *alm;
double *sqrts;
size_t l;
size_t m;
size_t k;

void init_vars() {
    lmax = 5000;
    mmax = lmax - 2;
    
    size_t sqrts_size = lmax + mmax + 10;
    sqrts = (double*)calloc(sqrts_size, sizeof(double));
    for (size_t i = 0; i < sqrts_size; ++i) {
        sqrts[i] = sqrt((double)(i + 1));
    }
    
    size_t alm_size = 2 * (lmax * mmax);
    alm = (double*)malloc(alm_size * sizeof(double));
    
    k = 0;
}

void loop();