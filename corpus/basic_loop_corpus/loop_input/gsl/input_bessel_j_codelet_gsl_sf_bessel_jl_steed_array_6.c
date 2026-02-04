#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int lmax = 1000000;
double x = 1.5;
double *jl_x;
double inv_fact = 1.0;
double x_l = 1.0;
int l;

void init_vars() {
    jl_x = (double*)aligned_alloc(32, (lmax + 1) * sizeof(double));
}