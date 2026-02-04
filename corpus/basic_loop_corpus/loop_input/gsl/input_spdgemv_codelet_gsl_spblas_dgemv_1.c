#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

double beta = 1.5;
size_t j;
size_t incY = 1;
size_t lenY;
double *Y;
size_t jy;

void init_vars() {
    lenY = 134217728 / sizeof(double);  // ~1GB of data to ensure ~0.01s runtime on modern CPU
    Y = (double*)aligned_alloc(32, lenY * sizeof(double));
    if (!Y) {
        exit(1);
    }
    for (size_t i = 0; i < lenY; ++i) {
        Y[i] = (double)(i + 1);
    }
    beta = 1.5;
    incY = 1;
    jy = 0;
}