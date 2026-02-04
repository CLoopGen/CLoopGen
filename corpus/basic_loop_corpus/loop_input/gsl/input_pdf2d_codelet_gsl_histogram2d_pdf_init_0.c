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
size_t nx;

static double *alloc_and_init_range(size_t len) {
    double *arr = (double *)calloc(len, sizeof(double));
    return arr;
}

void init_vars() {
    nx = 16777216; // ~134MB for two arrays of doubles (nx+1 and nx), targets ~0.01 sec on modern CPU

    h = (gsl_histogram2d *)malloc(sizeof(gsl_histogram2d));
    p = (gsl_histogram2d_pdf *)malloc(sizeof(gsl_histogram2d_pdf));

    h->nx = nx;
    h->ny = 1;
    p->nx = nx;
    p->ny = 1;

    h->xrange = alloc_and_init_range(nx + 1);
    p->xrange = alloc_and_init_range(nx + 1);

    h->yrange = alloc_and_init_range(nx + 1);
    p->yrange = alloc_and_init_range(nx + 1);
    p->sum = alloc_and_init_range(nx * 1 + 1);

    h->bin = alloc_and_init_range(nx * 1);

}