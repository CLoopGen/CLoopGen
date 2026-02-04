#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

size_t dim;
double y[65536];
double yerr[65536];
size_t i;
double *y_onestep;

void init_vars() {
    dim = 65536;
    y_onestep = (double*)malloc(dim * sizeof(double));
    for (i = 0; i < dim; i++) {
        y[i] = 1.0 + (double)(i % 100) / 100.0;
        y_onestep[i] = 0.9 + (double)(i % 100) / 100.0;
        yerr[i] = 0.0;
    }
}