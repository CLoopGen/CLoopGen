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
for (i = 0; i < nx; i++) {
    double xi = (h->xrange[i + 1] + h->xrange[i]) * 0.5;
    double wi = 0;
    int has_positive = 0;
    for (j = 0; j < ny; j++) {
        double wij = h->bin[i * ny + j];
        if (wij <= 0) continue;
        wi += wij;
        has_positive = 1;
    }
    if (has_positive && wi > 0) {
        long double prev_W = W;
        W += wi;
        wmean = (prev_W > 0) ? wmean + (xi - wmean) * (wi / W) : xi;
    }
}
}
