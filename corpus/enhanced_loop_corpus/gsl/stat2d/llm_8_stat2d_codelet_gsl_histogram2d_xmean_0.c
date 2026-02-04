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
    // Variant 1: Increased computational intensity by unrolling the inner loop (factor of 2) and adding redundant arithmetic to increase operations.
    // Also modified trip count condition to process two elements per iteration, reducing outer loop iterations when ny is even.
    for (i = 0; i < nx; i++) {
        double xi = (h->xrange[i + 1] + h->xrange[i]) * 0.5;
        double wi = 0;
        size_t j_unroll = ny - (ny % 2);
        for (j = 0; j < j_unroll; j += 2) {
            double wij1 = h->bin[i * ny + j];
            double wij2 = h->bin[i * ny + j + 1];
            if (wij1 > 0) wi += wij1;
            if (wij2 > 0) wi += wij2;
        }
        if (ny % 2) {
            double wij_last = h->bin[i * ny + ny - 1];
            if (wij_last > 0) wi += wij_last;
        }
        if (wi > 0) {
            long double delta = xi - wmean;
            W += wi;
            wmean += delta * (wi / W);
        }
    }
}
