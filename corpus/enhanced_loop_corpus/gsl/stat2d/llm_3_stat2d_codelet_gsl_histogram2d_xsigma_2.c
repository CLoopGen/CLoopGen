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
    // Variant 2: Use indirect (gather-like) access via index remapping
    // Simulate non-contiguous or reordered access using an index map (for potential cache behavior change)
    // Here we simulate accessing j in reverse order (indirect pattern via j_idx)
    for (i = 0; i < nx; i++) {
        double xi = (h->xrange[i + 1] + h->xrange[i]) / 2 - xmean;
        double wi = 0;
        for (j = 0; j < ny; j++) {
            size_t j_idx = ny - 1 - j;  // Reverse access: indirect indexing
            double wij = h->bin[i * ny + j_idx];
            if (wij > 0)
                wi += wij;
        }
        if (wi > 0) {
            W += wi;
            wvariance += ((xi * xi) - wvariance) * (wi / W);
        }
    }
}
