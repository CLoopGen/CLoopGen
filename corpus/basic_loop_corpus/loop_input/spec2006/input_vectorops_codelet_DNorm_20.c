#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

double *vec;
int n;
int x;
double sum;

void init_vars() {
    n = 16777216; // 16M elements, ~128MB for double array
    vec = (double*)aligned_alloc(32, n * sizeof(double));
    sum = 123.456;
    if (!vec) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }
    for (int i = 0; i < n; i++) {
        vec[i] = (double)(i + 1) * 2.5;
    }
}