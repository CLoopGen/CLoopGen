#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int lmax = 1000000;
double *jl_x;
double x_inv = 0.001;
double FP;
double XP2 = 1.5;
double PL = 2.0;
int L;
int LP;

void init_vars() {
    size_t array_size = (lmax + 10) * sizeof(double);
    jl_x = (double*)aligned_alloc(32, array_size);
    if (!jl_x) {
        exit(1);
    }

    for (int i = 0; i < lmax + 10; ++i) {
        jl_x[i] = 1.0 + 0.01 * i;
    }

    L = lmax + 5;
}