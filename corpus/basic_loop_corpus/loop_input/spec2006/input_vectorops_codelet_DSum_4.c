#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

double *vec;
int n;
double sum;
int x;

void init_vars() {
    n = 16777216; // 16M elements, ~128 MB of data (16M * sizeof(double) = 128 MB)
    vec = (double*)aligned_alloc(32, n * sizeof(double));
    if (!vec) {
        exit(1);
    }
    for (int i = 0; i < n; i++) {
        vec[i] = 1.0;
    }
    sum = 0.0;
    x = 0;
}