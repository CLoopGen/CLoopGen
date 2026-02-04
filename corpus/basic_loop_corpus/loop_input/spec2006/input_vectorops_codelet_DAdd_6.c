#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <time.h>

double *vec1;
double *vec2;
int n;
int x;

void init_vars() {
    n = 134217728; // 134217728 * sizeof(double) = 1073741824 bytes ~ 1GB total for two arrays, each ~512MB
    vec1 = (double*)aligned_alloc(32, n * sizeof(double));
    vec2 = (double*)aligned_alloc(32, n * sizeof(double));

    if (!vec1 || !vec2) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        vec1[i] = (double)(rand() % 1000) / 10.0;
        vec2[i] = (double)(rand() % 1000) / 10.0;
    }
}