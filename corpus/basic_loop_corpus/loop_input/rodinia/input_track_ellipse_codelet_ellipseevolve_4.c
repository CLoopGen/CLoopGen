#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

double *r0;
int Np;
int i;
double *r;

void init_vars() {
    Np = 16777216; // 16M elements, ~128MB for double array

    r0 = (double *)aligned_alloc(32, Np * sizeof(double));
    r = (double *)aligned_alloc(32, Np * sizeof(double));

    for (i = 0; i < Np; i++) {
        r[i] = (double)(i & 0xFF);
    }
}