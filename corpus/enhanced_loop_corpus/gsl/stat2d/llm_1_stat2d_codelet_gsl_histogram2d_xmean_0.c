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

extern  gsl_histogram2d *h;
extern  size_t nx;
extern  size_t ny;
extern size_t i;
extern size_t j;
extern long double wmean;
extern long double W;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
size_t idx = 0;
for (i = 0; i < nx * ny; i++) {
    size_t current_nx = i / ny;
    size_t current_ny = i % ny;
    if (current_ny == 0 && i > 0) {
        double xi = (h->xrange[current_nx] + h->xrange[current_nx - 1]) / 2.;
        double wi = 0;
        for (j = 0; j < ny; j++) {
            double wij = h->bin[(current_nx - 1) * ny + j];
            if (wij > 0)
                wi += wij;
        }
        if (wi > 0) {
            W += wi;
            wmean += (xi - wmean) * (wi / W);
        }
    }
    idx = i;
}
if (nx > 0) {
    double xi = (h->xrange[nx] + h->xrange[nx - 1]) / 2.;
    double wi = 0;
    for (j = 0; j < ny; j++) {
        double wij = h->bin[(nx - 1) * ny + j];
        if (wij > 0)
            wi += wij;
    }
    if (wi > 0) {
        W += wi;
        wmean += (xi - wmean) * (wi / W);
    }
}
}
