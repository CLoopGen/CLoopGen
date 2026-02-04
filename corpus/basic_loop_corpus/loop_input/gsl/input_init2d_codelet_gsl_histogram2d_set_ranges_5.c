#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdint.h>

typedef struct {
    size_t nx;
    size_t ny;
    double *xrange;
    double *yrange;
    double *bin;
} gsl_histogram2d;

gsl_histogram2d *h;
double xrange[1048576]; // ~8MB of data to target 0.01 sec runtime
size_t i;
size_t nx = 1048575; // Ensures loop from 0 to nx (inclusive) accesses valid xrange indices

void init_vars() {
    h = (gsl_histogram2d*)malloc(sizeof(gsl_histogram2d));
    if (!h) return;
    h->nx = nx;
    h->ny = 0;
    h->xrange = (double*)malloc((nx + 1) * sizeof(double));
    h->yrange = NULL;
    h->bin = NULL;
    for (size_t j = 0; j <= nx; j++) {
        xrange[j] = (double)(j * 2); // Initialize source data
    }
}