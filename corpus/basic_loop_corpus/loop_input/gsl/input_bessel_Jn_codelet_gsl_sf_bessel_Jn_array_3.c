#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <math.h>

int nmin;
int nmax;
double x;
double *result_array;
double Jnp1;
double Jn;
double Jnm1;
int n;

void init_vars() {
    x = 100.0;
    nmax = 2000000;
    nmin = 0;
    size_t array_size = (size_t)(nmax - nmin + 1);
    result_array = (double*)aligned_alloc(32, array_size * sizeof(double));
    if (!result_array) {
        exit(1);
    }

    for (size_t i = 0; i < array_size; i++) {
        result_array[i] = 0.0;
    }

    Jn = 1.0;
    Jnp1 = 0.5;
    Jnm1 = 0.0;
    n = nmax;
}