#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

#define DATA_SIZE_MB 64
#define TOTAL_DOUBLES (DATA_SIZE_MB * (1 << 20) / sizeof(double))

double h = 0.01;
size_t dim = TOTAL_DOUBLES;
double *_usr_y0;
double *y;
double *ytmp;
double *k;
size_t i;

void init_vars() {
    y = aligned_alloc(32, dim * sizeof(double));
    _usr_y0 = aligned_alloc(32, dim * sizeof(double));
    ytmp = aligned_alloc(32, dim * sizeof(double));
    k = aligned_alloc(32, dim * sizeof(double));

    for (size_t idx = 0; idx < dim; idx++) {
        y[idx] = (double)(idx % 128) / 128.0;
        _usr_y0[idx] = (double)(idx % 64) / 64.0;
        k[idx] = (double)(idx % 256) / 256.0;
        ytmp[idx] = 0.0;
    }
}