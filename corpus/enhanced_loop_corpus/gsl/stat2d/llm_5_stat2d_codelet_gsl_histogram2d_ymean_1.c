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
for (j = 0; j < ny; j++) {
    double yj = (h->yrange[j + 1] + h->yrange[j]) / 2.;
    double wj = 0;
    int has_positive = 0;
    for (i = 0; i < nx; i++) {
        double wij = h->bin[i * ny + j];
        if (wij <= 0) continue;
        wj += wij;
        has_positive = 1;
    }
    if (has_positive) {
        W += wj;
        wmean += (yj - wmean) * (wj / W);
    }
}
}
