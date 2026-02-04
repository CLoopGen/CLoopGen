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
    double xi = (h->xrange[i + 1] + h->xrange[i]) / 2.;
    double wi = 0;
    for (j = 0; j < ny; j++) {
        double wij = h->bin[i * ny + j];
        if (wij > 0)
            wi += wij;
    }
    if (wi > 0) {
        W += wi;
        wmean += (xi - wmean) * (wi / W);
    }
}

}
