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

static double *yrange_data;
static gsl_histogram2d h1_storage;
gsl_histogram2d *h1 = &h1_storage;
size_t i;

void init_vars() {
    h1->nx = 100;
    h1->ny = 240;
    
    yrange_data = (double *)calloc(h1->ny, sizeof(double));
    if (!yrange_data) exit(1);
    
    h1->xrange = (double *)calloc(h1->nx, sizeof(double));
    h1->yrange = yrange_data;
    h1->bin = (double *)calloc(h1->nx * h1->ny, sizeof(double));
    
    if (!h1->xrange || !h1->bin) exit(1);
}