#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct {
    size_t nx;
    size_t ny;
    double *xrange;
    double *yrange;
    double *sum;
} gsl_histogram2d_pdf;

typedef struct {
    size_t nx;
    size_t ny;
    double *xrange;
    double *yrange;
    double *bin;
} gsl_histogram2d;

gsl_histogram2d_pdf *p;
gsl_histogram2d *h;
size_t i;
size_t ny;

static double *alloc_aligned_double_array(size_t n) {
    void *ptr;
    if (posix_memalign(&ptr, 32, n * sizeof(double)) != 0) {
        exit(1);
    }
    return (double *)ptr;
}

void init_vars() {
    ny = 16777216 / sizeof(double);  // ~128MB of data for yrange arrays

    h = (gsl_histogram2d *)malloc(sizeof(gsl_histogram2d));
    p = (gsl_histogram2d_pdf *)malloc(sizeof(gsl_histogram2d_pdf));

    if (!h || !p) exit(1);

    h->ny = ny;
    p->ny = ny;

    h->yrange = alloc_aligned_double_array(ny + 1);
    p->yrange = alloc_aligned_double_array(ny + 1);

    for (size_t idx = 0; idx < ny + 1; idx++) {
        h->yrange[idx] = (double)(idx * 2);
    }
}