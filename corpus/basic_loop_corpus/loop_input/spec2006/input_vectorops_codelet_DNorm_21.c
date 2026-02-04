#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

double *vec;
int n = 134217728; // 128 million elements, ~1GB for doubles (8 bytes each)
int x;

void init_vars() {
    vec = (double*)calloc(n, sizeof(double));
    if (!vec) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
}