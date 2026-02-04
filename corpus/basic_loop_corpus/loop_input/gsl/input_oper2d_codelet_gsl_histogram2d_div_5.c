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

static double *bin1;
static double *bin2;
static double *xrange1;
static double *xrange2;
static double *yrange1;
static double *yrange2;

gsl_histogram2d *h1;
gsl_histogram2d *h2;
size_t i;

void init_vars() {
    h1 = (gsl_histogram2d *)malloc(sizeof(gsl_histogram2d));
    h2 = (gsl_histogram2d *)malloc(sizeof(gsl_histogram2d));

    h1->nx = 8000;
    h1->ny = 8000;
    h2->nx = 8000;
    h2->ny = 8000;

    size_t total_bins = h1->nx * h1->ny;

    bin1 = (double *)malloc(total_bins * sizeof(double));
    bin2 = (double *)malloc(total_bins * sizeof(double));
    xrange1 = (double *)malloc((h1->nx + 1) * sizeof(double));
    xrange2 = (double *)malloc((h2->nx + 1) * sizeof(double));
    yrange1 = (double *)malloc((h1->ny + 1) * sizeof(double));
    yrange2 = (double *)malloc((h2->ny + 1) * sizeof(double));

    for (size_t j = 0; j < total_bins; j++) {
        bin1[j] = (double)(j % 17 + 1);
        bin2[j] = (double)(j % 13 + 1);
    }

    for (size_t j = 0; j <= h1->nx; j++) {
        xrange1[j] = j * 1.0;
        xrange2[j] = j * 1.0;
    }
    for (size_t j = 0; j <= h1->ny; j++) {
        yrange1[j] = j * 1.0;
        yrange2[j] = j * 1.0;
    }

    h1->xrange = xrange1;
    h1->yrange = yrange1;
    h1->bin = bin1;

    h2->xrange = xrange2;
    h2->yrange = yrange2;
    h2->bin = bin2;
}