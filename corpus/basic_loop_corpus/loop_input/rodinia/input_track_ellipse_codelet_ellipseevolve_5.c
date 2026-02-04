#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int Np;
int i;
double *r;
double *r_old;

void init_vars() {
    Np = 134217728; // 134217728 elements * sizeof(double) = ~1024 MB, adjust for ~0.01s runtime
    r = (double*)aligned_alloc(32, Np * sizeof(double));
    r_old = (double*)aligned_alloc(32, Np * sizeof(double));

    for (i = 0; i < Np; i++) {
        r[i] = (double)(i % 1000) + 0.5;
        r_old[i] = 0.0;
    }
}