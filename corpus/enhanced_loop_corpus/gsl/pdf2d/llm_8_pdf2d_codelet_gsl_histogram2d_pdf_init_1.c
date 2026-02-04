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

extern gsl_histogram2d_pdf *p;
extern  gsl_histogram2d *h;
extern size_t i;
extern  size_t ny;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t j;
    for (i = 0; i < ny + 1; i++) {
        double temp = h->yrange[i] + 0.0;
        p->yrange[i] = temp * 1.0;
    }
}
