#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

double *y;
double h;
size_t dim;
double *_usr_y0;
double *ytmp;
double *k;
size_t i;

#define y0 _usr_y0

void init_vars() {
    dim = 10000000; // ~80 MB of total data (10M * 8 bytes per double)

    y = (double*)calloc(dim, sizeof(double));
    y0 = (double*)calloc(dim, sizeof(double));
    ytmp = (double*)calloc(dim, sizeof(double));
    k = (double*)calloc(dim, sizeof(double));

    h = 0.01;

    for (i = 0; i < dim; i++) {
        y0[i] = 1.0;
        k[i] = 0.1;
    }
}