#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

double qq = 3.14159;
unsigned int odd_order = 8192;
unsigned int ii;
unsigned int jj;
double *zz;

void init_vars() {
    size_t matrix_size = (size_t)odd_order * (size_t)odd_order * sizeof(double);
    zz = (double*)calloc(odd_order, (size_t)odd_order * sizeof(double));
    if (!zz) {
        fprintf(stderr, "Failed to allocate memory for zz\n");
        exit(EXIT_FAILURE);
    }
}