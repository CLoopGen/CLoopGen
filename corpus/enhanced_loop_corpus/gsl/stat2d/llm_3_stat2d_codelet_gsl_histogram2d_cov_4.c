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
extern  double ymean;
extern  size_t nx;
extern  size_t ny;
extern size_t i;
extern size_t j;
extern long double wcovariance;
extern long double W;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Strided memory access with increased stride (Memory Access Pattern: strided access, simulate cache behavior change)
    size_t stride = 2;
    size_t j_limit = (ny / stride) * stride;
    size_t i_limit = (nx / stride) * stride;

    // Process elements with stride first
    for (j = 0; j < j_limit; j += stride) {
        for (i = 0; i < i_limit; i += stride) {
            double xi = (h->xrange[i + 1] + h->xrange[i]) / 2. - xmean;
            double yj = (h->yrange[j + 1] + h->yrange[j]) / 2. - ymean;
            double wij = h->bin[i * ny + j];
            if (wij > 0) {
                W += wij;
                wcovariance += ((xi * yj) - wcovariance) * (wij / W);
            }
        }
    }

    // Handle remaining elements (non-strided tail)
    for (j = 0; j < ny; j++) {
        for (i = 0; i < nx; i++) {
            if ((i % stride == 0) && (j % stride == 0)) continue; // Skip already processed
            double xi = (h->xrange[i + 1] + h->xrange[i]) / 2. - xmean;
            double yj = (h->yrange[j + 1] + h->yrange[j]) / 2. - ymean;
            double wij = h->bin[i * ny + j];
            if (wij > 0) {
                W += wij;
                wcovariance += ((xi * yj) - wcovariance) * (wij / W);
            }
        }
    }
}
