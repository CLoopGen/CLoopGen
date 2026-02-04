#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

double ec[] = {0.0, 0.0, 1.0/5, 0.0, 1.0/5, -1.0/5, 1.0/5};
size_t dim = 16777216; // ~16.7M elements to target ~0.01 sec runtime with 8-byte doubles (134 MB total)
double h = 0.01;
double yerr[16777216];
size_t i;
double * k1;
double * k3;
double * k4;
double * k5;
double * k6;

void init_vars() {
    k1 = (double*)aligned_alloc(32, sizeof(double) * dim);
    k3 = (double*)aligned_alloc(32, sizeof(double) * dim);
    k4 = (double*)aligned_alloc(32, sizeof(double) * dim);
    k5 = (double*)aligned_alloc(32, sizeof(double) * dim);
    k6 = (double*)aligned_alloc(32, sizeof(double) * dim);

    for (size_t idx = 0; idx < dim; idx++) {
        k1[idx] = 1.0;
        k3[idx] = 1.0;
        k4[idx] = 1.0;
        k5[idx] = 1.0;
        k6[idx] = 1.0;
    }
}