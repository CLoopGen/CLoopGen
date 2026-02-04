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
    // Variant 1: Change memory access pattern to strided access for bin array
    // Instead of accessing row-major i*ny + j, we precompute the base pointer for each row (strided by ny)
    for (i = 0; i < nx; i++) {
        double xi = (h->xrange[i + 1] + h->xrange[i]) / 2 - xmean;
        double wi = 0;
        double *bin_row = &(h->bin[i * ny]);  // Base pointer for row i
        for (j = 0; j < ny; j++) {
            double wij = bin_row[j];  // Strided access via precomputed row base
            if (wij > 0)
                wi += wij;
        }
        if (wi > 0) {
            W += wi;
            wvariance += ((xi * xi) - wvariance) * (wi / W);
        }
    }
}
