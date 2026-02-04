#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

int m;
int nmax;
double x;
double *result_array;
double p_n0;
double p_n1;
double p_n;
int j;

void init_vars() {
    m = 2;
    x = 1.5;
    p_n0 = 1.0;
    p_n1 = x * (m + 1);
    
    nmax = 20000000;  // Large enough to take ~0.01s on modern CPU
    
    result_array = (double*)aligned_alloc(32, (nmax + 2) * sizeof(double));
    if (!result_array) {
        exit(1);
    }
    
    for (int i = 0; i < nmax + 2; i++) {
        result_array[i] = 0.0;
    }
    
    result_array[m] = p_n0;
    result_array[m + 1] = p_n1;
}