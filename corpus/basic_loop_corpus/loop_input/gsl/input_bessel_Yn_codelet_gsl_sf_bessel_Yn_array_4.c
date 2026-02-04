#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <math.h>

int nmin = 0;
int nmax = 10000000; // Adjusted for ~0.01 sec runtime
double x = 1.5;
double *result_array;
double Ynp1;
double Yn = 1.0;
double Ynm1 = 0.5;
int n;

void init_vars() {
    size_t len = (size_t)(nmax - nmin + 1);
    result_array = (double*)aligned_alloc(32, len * sizeof(double));
    if (!result_array) {
        exit(1);
    }
    for (size_t i = 0; i < len; i++) {
        result_array[i] = 0.0;
    }
    Ynm1 = 0.5;
    Yn = 1.0;
}