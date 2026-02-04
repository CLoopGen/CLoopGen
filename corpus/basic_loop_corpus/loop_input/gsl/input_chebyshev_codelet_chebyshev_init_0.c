#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

size_t n;
double *diag;
double *subdiag;
size_t i;

void init_vars() {
    n = 16777216; // 16M elements, roughly 128MB for two arrays of doubles

    diag = (double*)calloc(n, sizeof(double));
    subdiag = (double*)calloc(n, sizeof(double));

    if (!diag || !subdiag) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
}