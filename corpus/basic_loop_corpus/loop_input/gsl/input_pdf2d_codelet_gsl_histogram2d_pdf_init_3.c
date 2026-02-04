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
size_t n;
double mean;
double sum;

static double *alloc_aligned_double_array(size_t count) {
    void *ptr;
    if (posix_memalign(&ptr, 32, count * sizeof(double)) != 0) {
        exit(1);
    }
    return (double *)ptr;
}

void init_vars() {
    n = 16777216; // ~128 MB of doubles (16M * 8 bytes), target ~0.01 sec runtime

    h = (gsl_histogram2d *)malloc(sizeof(gsl_histogram2d));
    p = (gsl_histogram2d_pdf *)malloc(sizeof(gsl_histogram2d_pdf));
    if (!h || !p) exit(1);

    h->nx = n;
    h->ny = 1;
    h->bin = alloc_aligned_double_array(n);

    p->nx = n;
    p->ny = 1;
    p->sum = alloc_aligned_double_array(n + 1);

    mean = 1.0;
    sum = 0.0;

    for (size_t idx = 0; idx < n; idx++) {
        h->bin[idx] = (double)(idx % 256) + 1.0;
    }

    for (size_t idx = 0; idx <= n; idx++) {
        p->sum[idx] = 0.0;
    }
}