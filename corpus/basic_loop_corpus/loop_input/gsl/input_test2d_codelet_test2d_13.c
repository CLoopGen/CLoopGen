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
gsl_histogram2d *h1;
size_t i;
int status;

static double *alloc_and_init_range(size_t size) {
    double *ptr = (double*)calloc(size, sizeof(double));
    for (size_t i = 0; i < size; i++) {
        ptr[i] = (double)(i % 1000) / 100.0;
    }
    return ptr;
}

void init_vars() {
    h = (gsl_histogram2d*)calloc(1, sizeof(gsl_histogram2d));
    h1 = (gsl_histogram2d*)calloc(1, sizeof(gsl_histogram2d));

    h->ny = 240;
    h1->ny = 240;

    h->yrange = alloc_and_init_range(240);
    h1->yrange = alloc_and_init_range(240);

    h->yrange[100] += 0.01;

    h->nx = 100;
    h1->nx = 100;
    h->xrange = alloc_and_init_range(101);
    h1->xrange = alloc_and_init_range(101);
    h->bin = (double*)calloc(100 * 100, sizeof(double));
    h1->bin = (double*)calloc(100 * 100, sizeof(double));

    i = 0;
    status = 0;
}