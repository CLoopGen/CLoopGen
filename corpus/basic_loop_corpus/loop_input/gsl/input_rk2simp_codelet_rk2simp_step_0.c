#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

double *y;
double h;
size_t dim;
double *_usr_y0;
double *ytmp;
size_t i;

#define DATA_SIZE_MB 64
#define TOTAL_DOUBLES (DATA_SIZE_MB * (1 << 20) / sizeof(double))

void init_vars() {
    dim = TOTAL_DOUBLES;

    y = (double *)aligned_alloc(32, dim * sizeof(double));
    _usr_y0 = (double *)aligned_alloc(32, dim * sizeof(double));
    ytmp = (double *)aligned_alloc(32, dim * sizeof(double));

    if (!y || !_usr_y0 || !ytmp) {
        fprintf(stderr, "Allocation failed\n");
        exit(EXIT_FAILURE);
    }

    h = 0.5;

    for (size_t idx = 0; idx < dim; idx++) {
        _usr_y0[idx] = (double)(idx % 100) / 10.0;
        ytmp[idx] = (double)(idx % 50) + 1.0;
        y[idx] = 0.0;
    }
}