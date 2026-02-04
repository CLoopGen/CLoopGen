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
    // Variant 1: Consecutive memory access by precomputing and storing xi values in a temporary array
    // This changes the access pattern of xrange to be computed once and stored consecutively
    
    double *xcenters = (double*)malloc(nx * sizeof(double));
    for (size_t k = 0; k < nx; k++) {
        xcenters[k] = (h->xrange[k + 1] + h->xrange[k]) / 2.0;
    }

    for (i = 0; i < nx; i++) {
        double xi = xcenters[i];
        double wi = 0;
        size_t offset = i * ny;
        // Inner loop accesses bin with consecutive j increment (already consecutive, but made explicit)
        for (j = 0; j < ny; j++) {
            double wij = h->bin[offset + j];  // consecutive access in inner dimension
            if (wij > 0)
                wi += wij;
        }
        if (wi > 0) {
            W += wi;
            wmean += (xi - wmean) * (wi / W);
        }
    }

    free(xcenters);
}
