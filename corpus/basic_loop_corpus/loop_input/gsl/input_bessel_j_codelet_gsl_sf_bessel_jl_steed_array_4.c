#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int lmax;
double *jl_x;
int j;

void init_vars() {
    size_t data_size = 64 * 1024 * 1024; // ~64MB of double data (~8M elements)
    lmax = (int)((data_size / sizeof(double)) - 1);
    jl_x = (double*)calloc((size_t)lmax + 1, sizeof(double));
    if (!jl_x) {
        exit(1);
    }
}