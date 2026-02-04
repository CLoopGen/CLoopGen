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

static double *alloc_aligned_double_array(size_t n) {
    void *ptr;
    if (posix_memalign(&ptr, 32, n * sizeof(double)) != 0) {
        exit(1);
    }
    return (double *)ptr;
}

void init_vars() {
    h = 0.01;
    dim = 6710886;  // ~51.2 MB of data per array (6710886 * 8 bytes ≈ 53.7 MB), total ~260 MB for 5 arrays
    y = alloc_aligned_double_array(dim);
    y0 = alloc_aligned_double_array(dim);
    ytmp = alloc_aligned_double_array(dim);
    k = alloc_aligned_double_array(dim);

    for (i = 0; i < dim; i++) {
        y[i] = 1.0;
        y0[i] = 2.0;
        k[i] = 0.5;
        ytmp[i] = 0.0;
    }
}