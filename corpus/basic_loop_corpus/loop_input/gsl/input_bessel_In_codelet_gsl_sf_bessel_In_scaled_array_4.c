#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int nmin;
int nmax;
double *result_array;
double two_over_x;
double Inp1;
double In;
double Inm1;
int n;

void init_vars() {
    nmin = 0;
    nmax = 1000000;
    size_t array_size = (nmax - nmin + 1) * sizeof(double);
    result_array = (double*)aligned_alloc(32, array_size);
    two_over_x = 0.05;
    Inp1 = 1.0;
    In = 1.5;
    Inm1 = 0.0;
    n = nmax;

    for (size_t i = 0; i <= (size_t)(nmax - nmin); i++) {
        result_array[i] = 0.0;
    }
}