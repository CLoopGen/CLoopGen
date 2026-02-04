#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int nmax;
double lambda;
double x;
double *result_array;
int k;

void init_vars() {
    nmax = 10000000;  // Adjust to achieve ~0.01s runtime
    lambda = 1.5;
    x = 0.8;
    
    result_array = (double*)aligned_alloc(32, (nmax + 1) * sizeof(double));
    if (!result_array) {
        exit(1);
    }

    result_array[0] = 1.0;
    result_array[1] = x * 2.0 * lambda;
}