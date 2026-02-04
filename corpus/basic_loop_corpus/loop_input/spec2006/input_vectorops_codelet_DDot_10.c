#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <time.h>

double *vec1;
double *vec2;
int n;
double result;
int x;

void init_vars() {
    n = 16777216; // 16M elements, ~256MB total for two double arrays

    vec1 = (double*)aligned_alloc(32, n * sizeof(double));
    vec2 = (double*)aligned_alloc(32, n * sizeof(double));

    if (!vec1 || !vec2) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        vec1[i] = (double)(rand() % 1000) / 10.0;
        vec2[i] = (double)(rand() % 1000) / 10.0;
    }

    result = 0.0;
    x = 0;
}