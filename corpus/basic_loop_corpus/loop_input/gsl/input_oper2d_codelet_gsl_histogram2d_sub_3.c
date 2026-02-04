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
    // Aim for ~64MB of data (two arrays of doubles, each ~32MB)
    // Each bin array element is 8 bytes; total elements ~ 8M per array
    size_t total_elements = 8000000; // ~64MB for two bins

    // Choose nx and ny such that nx * ny = total_elements
    h1->nx = 2000;
    h1->ny = total_elements / h1->nx;
    while (h1->nx * h1->ny != total_elements) {
        h1->nx++;
        h1->ny = total_elements / h1->nx;
    }

    h2->nx = h1->nx;
    h2->ny = h1->ny;

    size_t nx = h1->nx;
    size_t ny = h1->ny;

    bin1 = (double*)calloc(total_elements, sizeof(double));
    bin2 = (double*)calloc(total_elements, sizeof(double));
    xrange1 = (double*)calloc(nx + 1, sizeof(double));
    xrange2 = (double*)calloc(nx + 1, sizeof(double));
    yrange1 = (double*)calloc(ny + 1, sizeof(double));
    yrange2 = (double*)calloc(ny + 1, sizeof(double));

    h1->bin = bin1;
    h1->xrange = xrange1;
    h1->yrange = yrange1;

    h2->bin = bin2;
    h2->xrange = xrange2;
    h2->yrange = yrange2;

    // Initialize bin data to some non-zero values to make subtraction meaningful
    for (size_t j = 0; j < total_elements; j++) {
        bin1[j] = (double)(j % 1000) / 10.0;
        bin2[j] = (double)(j % 500) / 20.0;
    }

    // Initialize range arrays
    for (size_t j = 0; j <= nx; j++) {
        xrange1[j] = j * 1.0;
        xrange2[j] = j * 1.1;
    }
    for (size_t j = 0; j <= ny; j++) {
        yrange1[j] = j * 0.5;
        yrange2[j] = j * 0.6;
    }
}

// Allocate structs at file scope via pointers to allow full control in init_vars
static gsl_histogram2d _h1 = {0};
static gsl_histogram2d _h2 = {0};

gsl_histogram2d *h1 = &_h1;
gsl_histogram2d *h2 = &_h2;