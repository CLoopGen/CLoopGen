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

size_t ny = 10000000; // 10M elements to target ~0.01 sec runtime
double *yrange;
size_t j;
gsl_histogram2d *h;

void init_vars() {
    // Allocate yrange array with ny + 1 elements to accommodate index from 0 to ny
    yrange = (double*)calloc(ny + 1, sizeof(double));
    if (!yrange) {
        exit(1);
    }

    // Allocate histogram structure
    h = (gsl_histogram2d*)malloc(sizeof(gsl_histogram2d));
    if (!h) {
        exit(1);
    }

    // Initialize h members
    h->nx = 0;
    h->ny = ny;

    // Allocate yrange in histogram also with ny + 1 elements
    h->yrange = (double*)malloc((ny + 1) * sizeof(double));
    if (!h->yrange) {
        exit(1);
    }

    h->xrange = NULL;
    h->bin = NULL;

    // Initialize source yrange with dummy data
    for (size_t i = 0; i <= ny; i++) {
        yrange[i] = (double)i * 0.1;
    }
}