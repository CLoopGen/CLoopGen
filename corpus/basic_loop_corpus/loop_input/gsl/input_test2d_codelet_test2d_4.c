#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct {
    size_t nx;
    size_t ny;
    double *xrange;
    double *yrange;
    double *bin;
} gsl_histogram2d;

gsl_histogram2d *h;
gsl_histogram2d *g;
size_t i;

static double *alloc_aligned_double_array(size_t n) {
    void *ptr;
    if (posix_memalign(&ptr, 32, n * sizeof(double)) != 0) {
        exit(1);
    }
    return (double *)ptr;
}

void init_vars() {
    h = (gsl_histogram2d *)malloc(sizeof(gsl_histogram2d));
    g = (gsl_histogram2d *)malloc(sizeof(gsl_histogram2d));
    if (!h || !g) exit(1);

    h->nx = 107;
    h->ny = 239;
    g->nx = 107;
    g->ny = 239;

    size_t total_bins = h->nx * h->ny;

    h->xrange = alloc_aligned_double_array(h->nx + 1);
    h->yrange = alloc_aligned_double_array(h->ny + 1);
    h->bin = alloc_aligned_double_array(total_bins);

    g->xrange = alloc_aligned_double_array(g->nx + 1);
    g->yrange = alloc_aligned_double_array(g->ny + 1);
    g->bin = alloc_aligned_double_array(total_bins);
}