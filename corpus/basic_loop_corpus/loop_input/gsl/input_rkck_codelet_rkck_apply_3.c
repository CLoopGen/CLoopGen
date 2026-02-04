#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <inttypes.h>
#include <math.h>

double b5[] = {0.1, 0.2, 0.3, 0.4};
size_t dim = 16777216; // ~128 MB of data (16M * sizeof(double) * 4 arrays ≈ 128MB), adjust for ~0.01s runtime
double h = 0.01;
double y[16777216];
size_t i;
double *k1;
double *k2;
double *k3;
double *k4;
double *ytmp;

void init_vars() {
    k1 = malloc(dim * sizeof(double));
    k2 = malloc(dim * sizeof(double));
    k3 = malloc(dim * sizeof(double));
    k4 = malloc(dim * sizeof(double));
    ytmp = malloc(dim * sizeof(double));

    for (size_t idx = 0; idx < dim; idx++) {
        y[idx] = 0.1 * idx;
        k1[idx] = 0.01 * idx;
        k2[idx] = 0.02 * idx;
        k3[idx] = 0.03 * idx;
        k4[idx] = 0.04 * idx;
    }
}