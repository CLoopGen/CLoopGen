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

extern size_t ny;
extern double *yrange;
extern size_t j;
extern gsl_histogram2d *h;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double *h_yrange = h->yrange;
    const double *src_yrange = yrange;
    for (j = 0; j <= ny; j += 2) {
        h_yrange[j] = src_yrange[j];
        if (j + 1 <= ny) {
            h_yrange[j + 1] = src_yrange[j + 1];
        }
    }
}
