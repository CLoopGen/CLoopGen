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

double yrange[1048576]; // 8MB of data (1M doubles)
size_t i;
size_t ny = 1048575; // Ensures loop runs from 0 to ny inclusive without OOB

gsl_histogram2d *h;

void init_vars() {
    h = (gsl_histogram2d*)malloc(sizeof(gsl_histogram2d));
    if (!h) exit(1);

    h->nx = 0;
    h->ny = ny;
    h->xrange = NULL;
    h->yrange = (double*)malloc((ny + 1) * sizeof(double));
    h->bin = NULL;

    if (!h->yrange) exit(1);
}