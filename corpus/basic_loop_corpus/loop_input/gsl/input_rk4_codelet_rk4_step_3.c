#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

double *y;
double h;
size_t dim;
double *k;
size_t i;

void init_vars() {
    dim = 10000000; // ~160 MB of data (2 arrays of double, each 8 bytes)
    h = 0.01;

    y = (double*)calloc(dim, sizeof(double));
    k = (double*)calloc(dim, sizeof(double));

    for (size_t idx = 0; idx < dim; idx++) {
        y[idx] = 1.0 / (idx + 1);
        k[idx] = 2.0 * (idx % 2) - 1.0;
    }
}