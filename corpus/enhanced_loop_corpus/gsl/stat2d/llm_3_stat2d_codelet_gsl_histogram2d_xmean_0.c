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



void loop() {
    // Variant 2: Strided memory access pattern for the bin array
    // Instead of accessing row-major (i-stride), we transpose the loop order conceptually
    // and use strided access across rows for better cache behavior in some architectures
    // We accumulate wi per column-first traversal with stride `ny` in the bin array

    double *wi_accum = (double*)calloc(nx, sizeof(double));

    // Traverse j first (columns), then i (rows) — transposed iteration
    for (j = 0; j < ny; j++) {
        for (i = 0; i < nx; i++) {
            size_t index = i * ny + j;  // Strided access: step of ny between consecutive i
            double wij = h->bin[index];
            if (wij > 0) {
                wi_accum[i] += wij;
            }
        }
    }

    // Now process each i with accumulated wi
    for (i = 0; i < nx; i++) {
        double xi = (h->xrange[i + 1] + h->xrange[i]) / 2.0;
        double wi = wi_accum[i];
        if (wi > 0) {
            W += wi;
            wmean += (xi - wmean) * (wi / W);
        }
    }

    free(wi_accum);
}
