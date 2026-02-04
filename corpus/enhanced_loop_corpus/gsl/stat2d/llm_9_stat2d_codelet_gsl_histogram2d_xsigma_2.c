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
extern  double xmean;
extern  size_t nx;
extern  size_t ny;
extern size_t i;
extern size_t j;
extern long double wvariance;
extern long double W;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
size_t stride = 1;
for (i = 0; i < nx; i += stride) {
    double xi = (h->xrange[i + 1] + h->xrange[i]) / 2 - xmean;
    double wi = 0;
    size_t unroll_factor = (ny >= 4) ? 4 : 1;
    size_t remainder = ny % unroll_factor;
    j = 0;
    if (unroll_factor == 4) {
        for (; j < ny - remainder; j += 4) {
            double wij0 = h->bin[i * ny + j];
            double wij1 = h->bin[i * ny + j + 1];
            double wij2 = h->bin[i * ny + j + 2];
            double wij3 = h->bin[i * ny + j + 3];
            wi += (wij0 > 0) ? wij0 : 0;
            wi += (wij1 > 0) ? wij1 : 0;
            wi += (wij2 > 0) ? wij2 : 0;
            wi += (wij3 > 0) ? wij3 : 0;
        }
    }
    for (; j < ny; j++) {
        double wij = h->bin[i * ny + j];
        if (wij > 0) wi += wij;
    }
    if (wi > 0) {
        W += wi;
        wvariance += ((xi * xi) - wvariance) * (wi / W);
    }
}
}
