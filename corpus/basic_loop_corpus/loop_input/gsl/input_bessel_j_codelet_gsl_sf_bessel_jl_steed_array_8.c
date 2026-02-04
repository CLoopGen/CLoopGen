#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int lmax = 131072;
double W = 1.5;
int L;

double *jl_x;

void init_vars() {
    jl_x = (double *)aligned_alloc(32, (lmax + 1) * sizeof(double));
    if (!jl_x) {
        exit(1);
    }
    for (int i = 1; i <= lmax; i++) {
        jl_x[i] = (double)(i & 1023) + 1.0;
    }
}