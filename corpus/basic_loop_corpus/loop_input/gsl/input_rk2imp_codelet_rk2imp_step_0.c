#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <inttypes.h>
#include <math.h>

double *y;
double h;
size_t dim;
double *_usr_y0;
double *Y1;
size_t i;

#define y0 _usr_y0

void init_vars() {
    dim = 10000000;  // Approximately 80 MB of data (10M * 8 bytes per double), adjust for ~0.01 sec runtime

    y = (double *)calloc(dim, sizeof(double));
    _usr_y0 = (double *)malloc(dim * sizeof(double));
    Y1 = (double *)malloc(dim * sizeof(double));

    h = 0.001;

    for (i = 0; i < dim; i++) {
        _usr_y0[i] = 0.1 * i;
        Y1[i] = 0.2 * i;
    }
}